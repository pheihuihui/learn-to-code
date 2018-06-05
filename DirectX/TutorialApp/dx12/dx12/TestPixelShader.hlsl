struct PixelShaderInput
{
    float4 pos : SV_POSITION;
    float3 color : COLOR0;
};

float4 main() : SV_TARGET
{
	return float4(0.9f, 0.9f, 0.9f, 0.9f);
}