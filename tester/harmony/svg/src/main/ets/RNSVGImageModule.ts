/*
 * Copyright (c) 2024 Huawei Device Co., Ltd. All rights reserved
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 */

import { TurboModule } from "@rnoh/react-native-openharmony/ts";
import { BusinessError } from '@ohos.base';
import image from '@ohos.multimedia.image';
import http from '@ohos.net.http';
import ResponseCode from '@ohos.net.http';
import buffer from '@ohos.buffer';
import Logger from './Logger'

export class RNSVGImageModule extends TurboModule {
  pixelMap: image.PixelMap | undefined = undefined
  sourceType: string = 'image/png'
  formatList: Map<string, string> = new Map([
    ['image/jpeg', 'image/jpeg'],
    ['image/png', 'image/png'],
    ['image/webp', 'image/webp'],
  ])

  public static readonly NAME = 'RNSVGImageModule';

  async getBase64String(uri: string): Promise<string> {
    if (uri.startsWith('data:')) {
      return Promise.resolve(uri);
    }
    let image: image.PixelMap | undefined = undefined;
    try {
      if (uri.includes('http')) {
        image = await this.getPixelMapFromURL(uri);
      } else {
        //TODO get pixelMap from local uri
      }
      if (image === undefined) {
        let message = "Error! Failed to decode Bitmap, uri: " + uri;
        Logger.warn(message);
        return Promise.reject(message);
      } else {
        return Promise.resolve(this.pixelMapToBase64(image));
      }
    } catch (error) {
      let message = "Error! Failed to decode pixelMap: " + error.message;
      Logger.warn(message);
      Promise.reject(message);
    }
  }

  async getPixelMapFromURL(src: string): Promise<image.PixelMap> {
    let pixelMap: image.PixelMap | undefined = undefined;
    let data = await http.createHttp().request(src);
    if (data.responseCode == ResponseCode.ResponseCode.OK && data.result instanceof ArrayBuffer) {
      let imageData: ArrayBuffer = data.result;
      if (data.header.hasOwnProperty('content-type')) {
        this.sourceType = data.header['content-type'];
      }
      let imageSource: image.ImageSource = image.createImageSource(imageData);
      let imageInfo = await imageSource.getImageInfo();
      let imageWidth = Math.round(imageInfo.size.width);
      let imageHeight = Math.round(imageInfo.size.height);
      let options: image.InitializationOptions = {
        alphaType: 1,
        editable: false,
        pixelFormat: 3,
        scaleMode: 1,
        size: { width: imageWidth, height: imageHeight }
      };
      pixelMap = await imageSource.createPixelMap(options);
    }
    return pixelMap;
  }

  async pixelMapToBase64(pixelMap: image.PixelMap): Promise<string> {
    let base64Url: string = '';
    let imagePacker = image.createImagePacker();
    let packFormat: string = this.formatList.get(this.sourceType) ?? 'image/png';
    let packOptions: image.PackingOption = { format: packFormat, quality: 100 };
    let data: ArrayBuffer = await imagePacker.packing(pixelMap, packOptions);
    if (data) {
      let buf: buffer.Buffer = buffer.from(data);
      base64Url = buf.toString('base64', 0, buf.length);
      Logger.debug(`svgImage base64: data:${packFormat};base64,${base64Url}`);
    }
    return "data:" + packFormat + ";base64," + base64Url;
  }
}