#pragma once
#include "BasicMaterial.h"
#include "Core/API/Device.h"
#include "Core/API/Types.h"
#include "Core/Object.h"
#include "Scene/Material/MaterialTypes.slang"

namespace Falcor
{

class FALCOR_API InterfaceMaterial : public BasicMaterial
{
    FALCOR_OBJECT(InterfaceMaterial)
public:
    static ref<InterfaceMaterial> create(ref<Device> pDevice, const std::string& name = "")
    {
        return make_ref<InterfaceMaterial>(pDevice, name);
    }

    InterfaceMaterial(ref<Device> pDevice, const std::string& name);

    bool renderUI(Gui::Widgets& widget) override;

    ProgramDesc::ShaderModuleList getShaderModules() const override;

    TypeConformanceList getTypeConformances() const override;

    DefineList getDefines() const override;

    const MaterialParamLayout& getParamLayout() const override;

    SerializedMaterialParams serializeParams() const override;

    void deserializeParams(const SerializedMaterialParams& params) override;
};

}; // namespace Falcor