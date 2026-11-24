# 412FinalProject - Lab09

## Architecture Diagram:

<img width="1506" height="1866" alt="DamageArchitectureDiagram" src="https://github.com/user-attachments/assets/e0aac13a-e5b3-4bc2-b1c6-63d92f53ec58" />

If I were to add a destructible crate, the entire system would function as is. However, the crate would need its own actor component to handle health and receiving damage. The weapon would not need to be modified in any way because all it does is check against the target and use a generic 'ApplyDamage' to the target. The crate would then need a listener attached to know when it is being damaged and call the associated 'TakeDamage' function built into it. 

## Independent Improvement

For this lab I created a simple ammunition system attached to the weapon. It incorporates a maximum ammo and a reload function which refills it to max. I chose to add these systems to the gun itself to allow for object independent behavior. For example, if we were to implement a different type a gun, we would just have to clone the blueprint and assign different values. Then, if the player switched between them, each would have its own internal ammo state. 

# 412FinalProject - Lab08

## Architecture Diagram:
<img width="2196" height="2016" alt="AnimationDiagram" src="https://github.com/user-attachments/assets/6b696f72-303a-47ae-8d30-9f3553b03fcc" />

Gameplay owns state data (velocity, flags like bIsJumping, combat status) and only sets variables—it never decides which animation plays. Animation (AnimBP's EventGraph + AnimGraph) reads those variables and decides the pose: the EventGraph processes data, the State Machine picks the major state, and Blend Spaces blend locomotion. Directly calling animations from many gameplay functions creates coupling because transition rules, interruption priorities, and blending get scattered across business logic instead of living in one place—making conflicts likely and changes expensive. The fix: gameplay writes variables, AnimBP reads them and drives everything, so animation changes stay contained in AnimBP.


## Animation Responsibilities
In UE5, animation responsibilities are split into three distinct layers: Gameplay Logic generates raw data (speed, direction, state flags); Animation Blueprint's Event Graph reads and processes that data into variables; and the AnimGraph (using State Machines and Blend Spaces) consumes those variables to compute the final pose.

Gameplay Logic owns the truth. It calculates values like velocity or whether the character is falling, exposing them as variables. The State Machine lives inside the AnimGraph. It reads boolean/enum variables to decide which state (e.g., Idle, Run, Jump) the character should be in, handling transitions between them. The Blend Space is an asset that takes continuous input values (like speed and direction) and blends multiple animations together smoothly so the character doesn't snap between poses.

## Independent Improvement
For this lab I implemented an additive aim/upper-body layer that allows the player to aim independently of their movement direction. Additionally, there is a complete blend space for every combination of idle/walk/run in the eight possible 2-axis directions. Having access to a controller would provide even more granularity in possible animations. 
