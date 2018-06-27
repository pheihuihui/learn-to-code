#include "GRS.hlsli"

struct Vertex_VS_OUT {
	float4 pos : SV_POSITION;
	float4 color : UserDefine0;
};

struct Pixel_PS_OUT{
	float4 color : SV_TARGET0;
};


[RootSignature(GRS)]
Pixel_PS_OUT main(Vertex_VS_OUT pixel){
	Pixel_PS_OUT rtval;
	rtval.color = pixel.color;
	return rtval;
}