#version 120
precision mediump float;

vec2 u_resolution = vec2(800.0, 800.0);
const float tau = 6.28318530717958647692;
uniform float time;
uniform float amplitude;
uniform float frequency;

void main()
{
    /*float amplitude = 5;
    float time = 0.5;*/
    //amplitude = 1f;
    vec2 position = gl_FragCoord.xy - u_resolution/2.0;

    float color = 1-smoothstep(2.0, 4.0, abs(length(position) - 250.0 
    + amplitude*sin(atan(position.y, position.x) * frequency*0.05 - time*10.0) * 2.0));

    gl_FragColor = vec4(vec3(color), 1.0);
}
