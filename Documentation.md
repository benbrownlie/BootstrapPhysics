
*Benjamin Brownlie* |
| --- |
| First Year Game Programming |
| Physics for Games Assessment |

## Game Structure
**Classes, Functions, and Variables**

## PhysicsGame Class

*Variables*

* > **private Renderer2D m_render-** Used to represent the renderer.
* > **private Font m_font-** Used to represent a font.
* > **private Scene m_scene-** Used to represent the scene.

*Functions*

* > **public virtual bool startup()-** Handles variable assignment and creating & adding actors to the scene when the program starts.
* > **public virtual void shutdown()-** Handles deleting variables when the program closes.
* > **public virtual void update(float deltatime)-** Checks for input presses.
* > **public virtual void draw()-** Used to render objects to the screen.

## PhysicsObject Class

*Functions*

* > **protected PhysicsObject(ShapeType shapeID) : m_shapeID(shapeID)-** Constructor for shape objects.
* > **public virtual void fixedUpdate(glm::vec2 gravity, float timeStep) = 0-** Handles gravity each frame.
* > **public virtual void draw() = 0-** draws the objects.
* > **public virtual void resetPosition()-** 
* > **public ShapeType getShapeID()-** Returns the variable m_shapeID.

## PhysicsProject Class

Calls game->run

## PhysicsScene Class

*Variables*



