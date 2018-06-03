//float4 main(float4 pos : POSITION) : SV_POSITION
//{
//	return pos;
//}

float4 main(float4 pos : POSITION) : SV_Position
{
    return pos;
}

//TODO_201806032315: HlslTools uses space to autocomplete, and has to be changed to tab;
//TODO_201806032315: Disable autocomplete in comments.
//TODO_201806032315: Some keywords still haven't been added in.