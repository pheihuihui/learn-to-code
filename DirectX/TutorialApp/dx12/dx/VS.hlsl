#include "GRS.hlsli"

struct Vertex_IA_OUT {
	uint vid : SV_VERTEXID;
	uint iid : SV_INSTANCEID;
};

struct Vertex_VS_OUT {
	float4 pos : SV_POSITION;
	float4 color : UserDefine0;
};

[RootSignature(GRS)]
Vertex_VS_OUT main(Vertex_IA_OUT vertex) {
	Vertex_VS_OUT rtval;
	rtval.pos = float4(0.0f, 0.0f, 0.0f, 0.0f);
    rtval.color = float4(0.0f, 0.0f, 0.0f, 0.0f);
	if(vertex.iid == 0){
		if(vertex.vid == 0){
			rtval.pos = float4(0.0f, 0.5f, 0.5f, 1.0f);
			rtval.color = float4(1.0f, 0.0f, 0.0f, 1.0f);
		}
		else if(vertex.vid == 1){
			rtval.pos = float4(0.5f, -0.5f, 0.5f, 1.0f);
			rtval.color = float4(0.0f, 1.0f, 0.0f, 1.0f);
		}
		else if(vertex.vid == 2){
			rtval.pos = float4(-0.5f, -0.5f, 0.5f, 1.0f);
			rtval.color = float4(0.0f, 0.0f, 1.0f, 1.0f);
		}
	}
	return rtval;
}