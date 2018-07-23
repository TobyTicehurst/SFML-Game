Any comments and suggestions are welcomed, please email me at tobyticehurst@hotmail.co.uk

Class Structure:

Game
  Game is the "main" class
  It cointains the main game loop which deals with input, updates objects, and draws objects each game loop
  It contains pointers to the high level objects and allows communication between them
  
StateMachine
  A state machine allows the application to be in one specific state at a time and run code relating to that state
  For example, in the main menu state, no code to do with the player or enemies needs to be run
  
  StateMainMenu and StatePlaying are the only states to currently exist
  
GUI
  GUI is responsible for "panels" which in turn own "widgets"
  widgets are objects that can in some way be interacted with, for example a button, a panel with buttons would be a menu
  
Maps
  Maps are storage classes which link a std::string to a resource allowing for fetching of resources via name
  this is temporary in some cases and will later be replaced with either "id tags" or direct pointers
  
Renderable
   A renderable contains a pointer to a texture and local position information
   This is combined with global position information (stored in Entity classes) to allow object to be rendered
    
Entity
   Entity has a pointer to a renderable and a global position
   The interpretation of this position can be window or world coordinates depending on the class
   The reason for seperating Entity and Renderable rather than having just one "Sprite" object is that many, many objects 
   will share the same local position information (and texture)
   This saves memory but adds a small proccessing cost, so may change after futher testing
   
Renderer
   The renderer owns a vector of pointers to "drawables" any object with a "draw" function
   These objects are mostly Entities
   The draw function in the main game loop causes each object to add to this vector and the whole vector is rendered
   in one go via Renderer::render
   This is to allow for future optimisations with batch rendering
   
Window
   Window is a child of sf::RenderWindow
   It deals with the "View" a 2D camera as well as window events eg closing/resizing
   Config contains a bunch of "option" variables
   
Utitity:

ptr is shorthand for std::unique_ptr (used frequently through the code)
nonCopyable is what it says, many objects use it as the Game class should never be copied/moved/changed after construction
Bin is a storage class; a vector of contiguous pointers. It is a generic kind of storage used for writing quick code
Other storage types are experimental, future tests required

Work In Progress:

  While the engine is done for now, the game proper is all still in progress, much of it not shown here
  Graphical elements are also not finished
  
