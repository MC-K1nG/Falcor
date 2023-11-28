# Volumetric-dev

-  BUG ? HomogeneousVolumeSampler.slang : sampleDistance
    
    `const float t = -log(1.f - u) / sigmaS[channel];` here should be sigmaT ?

- Optimization ? 
    
    seperate attenuationRay test into two steps
    
    1. anyHit with alphaTest (ignore the interface)

    2. for possible interface hit, compute tr


