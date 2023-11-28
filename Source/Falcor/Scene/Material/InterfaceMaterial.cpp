#include "InterfaceMaterial.h"
#include <pybind11/pytypes.h>
#include "GlobalState.h"
#include "Utils/Scripting/ScriptBindings.h"
#include "Utils/UI/Gui.h"
#include "InterfaceMaterialParamLayout.slang"
namespace Falcor
{
namespace
{
const char kShaderFile[] = "Rendering/Materials/InterfaceMaterial.slang";
} // namespace

InterfaceMaterial::InterfaceMaterial(ref<Device> pDevice, const std::string& name) : BasicMaterial(pDevice, name, MaterialType::Interface)
{
    // TODO
}

bool InterfaceMaterial::renderUI(Gui::Widgets& widget)
{
    // TODO
    return false;
}

ProgramDesc::ShaderModuleList InterfaceMaterial::getShaderModules() const
{
    return {ProgramDesc::ShaderModule::fromFile(kShaderFile)};
}

TypeConformanceList InterfaceMaterial::getTypeConformances() const
{
    return {{{"InterfaceMaterial", "IMaterial"}, (uint32_t)MaterialType::Interface}};
}

DefineList InterfaceMaterial::getDefines() const
{
    // TODO
    DefineList defines;
    return defines;
}

const MaterialParamLayout& InterfaceMaterial::getParamLayout() const
{
    return InterfaceMaterialParamLayout::layout();
}

SerializedMaterialParams InterfaceMaterial::serializeParams() const
{
    return InterfaceMaterialParamLayout::serialize(this);
}

void InterfaceMaterial::deserializeParams(const SerializedMaterialParams& params)
{
    InterfaceMaterialParamLayout::deserialize(this, params);
}

FALCOR_SCRIPT_BINDING(InterfaceMaterial)
{
    using namespace pybind11::literals;

    FALCOR_SCRIPT_BINDING_DEPENDENCY(BasicMaterial)

    pybind11::class_<InterfaceMaterial, BasicMaterial, ref<InterfaceMaterial>> material(m, "InterfaceMaterial");

    auto create = [](const std::string& name) { return InterfaceMaterial::create(accessActivePythonSceneBuilder().getDevice(), name); };
    material.def(pybind11::init(create), "name"_a = "");
}

}; // namespace Falcor