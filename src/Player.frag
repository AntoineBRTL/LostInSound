#version 330
precision mediump float;

uniform float radius;
uniform vec2 position;
uniform float glow;
uniform float time;

vec2 u_resolution = vec2(radius*2.0, radius*2.0);
vec2 screen_resolution = vec2(400.0/u_resolution.x, 400.0/u_resolution.y);

out vec4 fragColor;

void main()
{
    vec2 a = (vec2(radius + glow, radius + glow) + vec2(-position.x, position.y)/screen_resolution);
    vec2 b = (gl_FragCoord.xy)/(u_resolution);
    float d = distance(a, b);
    float alpha = d;

    float frequency = 0.5;
    float offet = 0.5;
    vec3 color;

    float minTint = 0.5;
    float maxTint = 1.0;
    color = vec3(
        offet + sin(2.0 * 3.14 * frequency * time),
        offet + sin(2.0 * 3.14 * frequency * time + radians(120.0)),
        offet + sin(2.0 * 3.14 * frequency * time + radians(240.0))
    );

    color = sqrt(color);

    fragColor = vec4(color, min(exp(-d * 2.5f), 0.5f));
}