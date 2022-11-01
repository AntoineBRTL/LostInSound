#version 330
precision mediump float;

#define GAMMA 1

uniform float radius;
uniform vec2 position;
out vec4 fragColor;
vec2 u_resolution = vec2(800.0, 800.0);
uniform float time;

float rand(vec2 co){
    return fract(sin(dot(co, vec2(12.9898, 78.233))) * 43758.5453);
}

vec3 getBackgroundColor()
{
    vec2 st = gl_FragCoord.xy/u_resolution.xy;
    float pixel = rand(st);
    return vec3((pixel / 50.0) + 0.1);
}

vec3 getColor()
{
    return (vec3(position.x, position.y, 0.25) + vec3(1.0)) / 2.0;
}

vec3 adjustGamma2(vec3 color)
{
    return sqrt(color);
}

void main()
{
    vec3 color = getColor();

    for(int i = 0; i < GAMMA; i++)
    {
        color = adjustGamma2(color);
    }

    fragColor = vec4(color, 1.0);
}