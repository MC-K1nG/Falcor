__exported import Rendering.Materials.IMaterial;
__exported import Rendering.Materials.InterfaceMaterialInstance;

struct InterfaceMaterial : MaterialBase, IMaterial
{
    typedef InterfaceMaterialInstance MaterialInstance;

    InterfaceMaterialInstance setupMaterialInstance(
        const MaterialSystem ms,
        const ShadingData sd,
        const ITextureSampler lod,
        const uint hits
    )
    {
        ShadingFrame sf = sd.frame;
        InterfaceMaterialInstance mi = { sf };

        return mi;
    }

    [Differentiable]
    InterfaceMaterialInstance setupDiffMaterialInstance(
        out DiffMaterialData diffData,
        const MaterialSystem ms,
        const ShadingData sd,
        const ITextureSampler lod,
        const uint hints
    )
    {
        //* No differentiable support
        InterfaceMaterialInstance mi;
        return mi;
    }
}
