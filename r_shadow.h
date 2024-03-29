
#ifndef R_SHADOW_H
#define R_SHADOW_H

#define R_SHADOW_SHADOWMAP_NUMCUBEMAPS 8

extern cvar_t r_shadow_bumpscale_basetexture;
extern cvar_t r_shadow_bumpscale_bumpmap;
extern cvar_t r_shadow_debuglight;
extern cvar_t r_shadow_gloss;
extern cvar_t r_shadow_gloss2intensity;
extern cvar_t r_shadow_glossintensity;
extern cvar_t r_shadow_glossexponent;
extern cvar_t r_shadow_gloss2exponent;
extern cvar_t r_shadow_glossexact;
extern cvar_t r_shadow_lightattenuationpower;
extern cvar_t r_shadow_lightattenuationscale;
extern cvar_t r_shadow_lightintensityscale;
extern cvar_t r_shadow_lightradiusscale;
extern cvar_t r_shadow_projectdistance;
extern cvar_t r_shadow_frontsidecasting;
extern cvar_t r_shadow_realtime_dlight;
extern cvar_t r_shadow_realtime_dlight_shadows;
extern cvar_t r_shadow_realtime_dlight_svbspculling;
extern cvar_t r_shadow_realtime_dlight_portalculling;
extern cvar_t r_shadow_realtime_world;
extern cvar_t r_shadow_realtime_world_lightmaps;
extern cvar_t r_shadow_realtime_world_shadows;
extern cvar_t r_shadow_realtime_world_compile;
extern cvar_t r_shadow_realtime_world_compileshadow;
extern cvar_t r_shadow_realtime_world_compilesvbsp;
extern cvar_t r_shadow_realtime_world_compileportalculling;
extern cvar_t r_shadow_scissor;
extern cvar_t r_shadow_polygonfactor;
extern cvar_t r_shadow_polygonoffset;
extern cvar_t r_shadow_texture3d;
extern cvar_t gl_ext_separatestencil;
extern cvar_t gl_ext_stenciltwoside;

// used by shader for bouncegrid feature
typedef struct r_shadow_bouncegrid_settings_s
{
	bool staticmode;
	bool bounceanglediffuse;
	bool directionalshading;
	bool includedirectlighting;
	bool blur;
	bool normalizevectors;
	int floatcolors;
	float dlightparticlemultiplier;
	bool hitmodels;
	float lightradiusscale;
	int maxbounce;
	float lightpathsize_initial;
	float lightpathsize_conespread;
	float particlebounceintensity;
	float particleintensity;
	int maxphotons;
	float energyperphoton;
	float spacing[3];
	int rng_type;
	int rng_seed;
	float bounceminimumintensity2;
}
r_shadow_bouncegrid_settings_t;

typedef struct r_shadow_bouncegrid_state_s
{
	r_shadow_bouncegrid_settings_t settings;
	bool capable;
	bool allowdirectionalshading;
	bool directional; // copied from settings.directionalshading after createtexture is decided
	bool createtexture; // set to true to recreate the texture rather than updating it - happens when size changes or directional changes
	rtexture_t *texture;
	matrix4x4_t matrix;
	vec_t intensity;
	double lastupdatetime;
	int resolution[3];
	int numpixels;
	int pixelbands;
	int pixelsperband;
	int bytesperband;
	float spacing[3];
	float ispacing[3];
	vec3_t mins;
	vec3_t maxs;
	vec3_t size;
	int maxsplatpaths;

	// per-frame data that is very temporary
	int numsplatpaths;
	struct r_shadow_bouncegrid_splatpath_s *splatpaths;
	int highpixels_index; // which one is active - this toggles when doing blur
	float *highpixels; // equals blurpixels[highpixels_index]
	float *blurpixels[2];
	unsigned char *u8pixels; // temporary processing buffer when outputting to rgba8 format
	unsigned short *fp16pixels; // temporary processing buffer when outputting to rgba16f format
}
r_shadow_bouncegrid_state_t;

extern r_shadow_bouncegrid_state_t r_shadow_bouncegrid_state;

void R_Shadow_Init(void);
bool R_Shadow_ShadowMappingEnabled(void);
void R_Shadow_VolumeFromList(int numverts, int numtris, const float *invertex3f, const int *elements, const int *neighbors, const vec3_t projectorigin, const vec3_t projectdirection, float projectdistance, int nummarktris, const int *marktris, vec3_t trismins, vec3_t trismaxs);
void R_Shadow_ShadowMapFromList(int numverts, int numtris, const float *vertex3f, const int *elements, int numsidetris, const int *sidetotals, const unsigned char *sides, const int *sidetris);
void R_Shadow_MarkVolumeFromBox(int firsttriangle, int numtris, const float *invertex3f, const int *elements, const vec3_t projectorigin, const vec3_t projectdirection, const vec3_t lightmins, const vec3_t lightmaxs, const vec3_t surfacemins, const vec3_t surfacemaxs);
int R_Shadow_CalcTriangleSideMask(const vec3_t p1, const vec3_t p2, const vec3_t p3, float bias);
int R_Shadow_CalcSphereSideMask(const vec3_t p1, float radius, float bias);
int R_Shadow_ChooseSidesFromBox(int firsttriangle, int numtris, const float *invertex3f, const int *elements, const matrix4x4_t *worldtolight, const vec3_t projectorigin, const vec3_t projectdirection, const vec3_t lightmins, const vec3_t lightmaxs, const vec3_t surfacemins, const vec3_t surfacemaxs, int *totals);
void R_Shadow_RenderLighting(int texturenumsurfaces, const msurface_t **texturesurfacelist);
void R_Shadow_RenderMode_Begin(void);
void R_Shadow_RenderMode_ActiveLight(const rtlight_t *rtlight);
void R_Shadow_RenderMode_Reset(void);
void R_Shadow_RenderMode_StencilShadowVolumes(bool zpass);
void R_Shadow_RenderMode_Lighting(bool stenciltest, bool transparent, bool shadowmapping, bool noselfshadowpass);
void R_Shadow_RenderMode_DrawDeferredLight(bool shadowmapping);
void R_Shadow_RenderMode_VisibleShadowVolumes(void);
void R_Shadow_RenderMode_VisibleLighting(bool stenciltest, bool transparent);
void R_Shadow_RenderMode_End(void);
void R_Shadow_ClearStencil(void);
void R_Shadow_SetupEntityLight(const entity_render_t *ent);

bool R_Shadow_ScissorForBBox(const float *mins, const float *maxs);

// these never change, they are used to create attenuation matrices
extern matrix4x4_t matrix_attenuationxyz;
extern matrix4x4_t matrix_attenuationz;

void R_Shadow_UpdateWorldLightSelection(void);

extern rtlight_t *r_shadow_compilingrtlight;

void R_RTLight_Update(rtlight_t *rtlight, int isstatic, matrix4x4_t *matrix, vec3_t color, int style, const char *cubemapname, int shadow, vec_t corona, vec_t coronasizescale, vec_t ambientscale, vec_t diffusescale, vec_t specularscale, int flags);
void R_RTLight_Compile(rtlight_t *rtlight);
void R_RTLight_Uncompile(rtlight_t *rtlight);

void R_Shadow_PrepareLights(int fbo, rtexture_t *depthtexture, rtexture_t *colortexture);
void R_Shadow_ClearShadowMapTexture(void);
void R_Shadow_DrawPrepass(void);
void R_Shadow_DrawLights(void);
void R_Shadow_DrawCoronas(void);

extern int maxshadowmark;
extern int numshadowmark;
extern int *shadowmark;
extern int *shadowmarklist;
extern int shadowmarkcount;
void R_Shadow_PrepareShadowMark(int numtris);

extern int maxshadowsides;
extern int numshadowsides;
extern unsigned char *shadowsides;
extern int *shadowsideslist;
void R_Shadow_PrepareShadowSides(int numtris);

void R_Shadow_PrepareModelShadows(void);

#define LP_LIGHTMAP		1
#define LP_RTWORLD		2
#define LP_DYNLIGHT		4
void R_LightPoint(float *color, const vec3_t p, const int flags);
void R_CompleteLightPoint(float *ambientcolor, float *diffusecolor, float *diffusenormal, const vec3_t p, const int flags);

void R_Shadow_DrawShadowMaps(void);
void R_Shadow_DrawModelShadows(void);

#endif
