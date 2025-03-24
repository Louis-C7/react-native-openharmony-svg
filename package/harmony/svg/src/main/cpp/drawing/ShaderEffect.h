/*
 * Copyright (c) 2024 Huawei Device Co., Ltd. All rights reserved
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 */

#pragma once

#include <memory>
#include <native_drawing/drawing_shader_effect.h>
#include <native_drawing/drawing_point.h>
#include <native_drawing/drawing_matrix.h>
#include <native_drawing/drawing_types.h>

namespace rnoh::drawing {

class ShaderEffect final {

    using UniqueNativeShaderEffect =
        std::unique_ptr<OH_Drawing_ShaderEffect, decltype(&OH_Drawing_ShaderEffectDestroy)>;

public:
    ShaderEffect();

    ShaderEffect(ShaderEffect const &other) = delete;
    ShaderEffect &operator=(ShaderEffect const &other) = delete;

    ShaderEffect(ShaderEffect &&other) = default;
    ShaderEffect &operator=(ShaderEffect &&other) = default;

    void ShaderEffectCreateLinearGradient(const OH_Drawing_Point2D *startPt, const OH_Drawing_Point2D *endPt,
                                          const uint32_t *colors, const float *pos, uint32_t size,
                                          OH_Drawing_TileMode mode, const OH_Drawing_Matrix *mat);

    void ShaderEffectCreateRadialGradient(const OH_Drawing_Point2D *startPt, float startRadius,
                                          const OH_Drawing_Point2D *endPt, float endRadius, const uint32_t *colors,
                                          const float *pos, uint32_t size, OH_Drawing_TileMode mode,
                                          const OH_Drawing_Matrix *mat);

    void ShaderEffectCreateImageShader(OH_Drawing_Image *image, OH_Drawing_TileMode tileX, OH_Drawing_TileMode tileY,
                                       const OH_Drawing_SamplingOptions *opt, const OH_Drawing_Matrix *mat);

    ~ShaderEffect() noexcept = default;

    OH_Drawing_ShaderEffect *get() const { return shaderEffect_.get(); }

private:
    UniqueNativeShaderEffect shaderEffect_;
};

} // namespace rnoh::drawing