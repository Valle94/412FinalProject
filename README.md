# 412FinalProject - Lab08

## Architecture Diagram:
<img width="2196" height="2016" alt="AnimationDiagram" src="https://github.com/user-attachments/assets/6b696f72-303a-47ae-8d30-9f3553b03fcc" />

Gameplay owns state data (velocity, flags like bIsJumping, combat status) and only sets variables—it never decides which animation plays. Animation (AnimBP's EventGraph + AnimGraph) reads those variables and decides the pose: the EventGraph processes data, the State Machine picks the major state, and Blend Spaces blend locomotion. Directly calling animations from many gameplay functions creates coupling because transition rules, interruption priorities, and blending get scattered across business logic instead of living in one place—making conflicts likely and changes expensive. The fix: gameplay writes variables, AnimBP reads them and drives everything, so animation changes stay contained in AnimBP.


## Animation Responsibilities
In UE5, animation responsibilities are split into three distinct layers: Gameplay Logic generates raw data (speed, direction, state flags); Animation Blueprint's Event Graph reads and processes that data into variables; and the AnimGraph (using State Machines and Blend Spaces) consumes those variables to compute the final pose.

Gameplay Logic owns the truth. It calculates values like velocity or whether the character is falling, exposing them as variables. The State Machine lives inside the AnimGraph. It reads boolean/enum variables to decide which state (e.g., Idle, Run, Jump) the character should be in, handling transitions between them. The Blend Space is an asset that takes continuous input values (like speed and direction) and blends multiple animations together smoothly so the character doesn't snap between poses.

## Independent Improvement
For this lab I implemented an additive aim/upper-body layer that allows the player to aim independently of their movement direction. Additionally, there is a complete blend space for every combination of idle/walk/run in the eight possible 2-axis directions. Having access to a controller would provide even more granularity in possible animations. 
