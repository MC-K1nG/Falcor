__exported import Rendering.Materials.IMaterialInstance;

import Scene.Material.VolumeProperties;

struct InterfaceMaterialInstance : MaterialInstanceBase, IMaterialInstance
{
    ShadingFrame sf;

    __init(const ShadingFrame sf) { this.sf = sf; }

    float3 eval<S : ISampleGenerator>(const ShadingData sd, const float3 wo, inout S sg) { return float3(.0f); }

    [Differentiable]
    float3 evalAD<S : ISampleGenerator>(const DiffMaterialData diffData, const ShadingData sd, const float3 wo, inout S sg)
    {
        return float3(.0f);
    }

    bool sample<S : ISampleGenerator>(const ShadingData sd, inout S sg, out BSDFSample result, bool useImportanceSampling = true)
    {
        float3 wiLocal = sf.toLocal(sd.V);
        result.wo = sf.fromLocal(-wiLocal);
        result.pdf = 1.f;
        result.weight = float3(1.f);
        result.lobeType = (uint)LobeType::DeltaTransmission;
        return true;
    }

    float evalPdf(const ShadingData sd, const float3 wo, bool useImportanceSampling = true) { return .0f; }

    BSDFProperties getProperties(const ShadingData sd)
    {
        BSDFProperties p = {};

        p.guideNormal = sf.N;
        p.roughness = .0f;
        p.diffuseReflectionAlbedo = float3(1.f);
        p.flags = (uint)BSDFProperties::Flags::IsInterface;

        return p;
    }

    uint getLobeTypes(const ShadingData sd)
    {
        return (uint)LobeType::DeltaTransmission; // TODO
    }

    bool hasVolumeProperties()
    {
        return false; // TODO
    }

    VolumeProperties getVolumeProperties()
    {
        VolumeProperties result;
        return result; // TODO
    }
};
