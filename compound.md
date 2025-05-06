# Compound Pattern
A compound pattern is a set of a few patterns that are combined to solve a general problem. 

The King of Compound Patterns - Model-View-Controller (MVC)

The secret to learning MVC: When you approach learning MVC by looking at the patterns, all of a sudden it starts to make sense. it’s just a few patterns put together.

1. You’re the user—you interact with the view.
2. The controller asks the model to change its state.
3. The controller may also ask the view to change.
4. The model notifies the view when its state has changed.
5. The view asks the model for state.

All the controller does is take user input from the view and send it to the model. Why have it at all if that is all it does? Why not just have the code in the view itself?
* you’ll complicate your view code because it now has two responsibilities: managing the user interface and dealing with the logic of how to control the model. 
* you’re tightly coupling your view to the model. If you want to reuse the view with another model, forget it. 
* The controller implements behavior for the view. It does not implement any application logic.

The model uses Observer to keep the views and controllers updated on the latest state changes. The view and the controller, on the other hand, implement the Strategy Pattern. The controller is the strategy of the view, and it can be easily exchanged with another controller if you want different behavior. The view itself also uses a pattern internally to manage the windows, buttons, and other components of the display: the Composite Pattern (mostly hidden behind GUI packages).

In thin client approaches, the model, most of the view, and the controller all reside in the server, with the browser providing a way to display the view, and to get input from the browser to the controller. Another approach is the single page application, where almost all of the model, view, and controller reside on the client side. Those are the two ends of the spectrum, and you’ll find frameworks that vary the extent to which each component adapt it such as Spring Web MVC, Django, ASP.NET MVC, AngularJS, EmberJS, JavaScriptMVC, Backbone.

* The Model View Controller (MVC) Pattern is a compound pattern consisting of the Observer, Strategy, and Composite Patterns.
* The model makes use of the Observer Pattern so that it can keep observers updated yet stay decoupled from them.
* The controller is the Strategy for the view. The view can use different implementations of the controller to get different behavior.
* The view uses the Composite Pattern to implement the user interface, which usually consists of nested components like panels, frames, and buttons.
* These patterns work together to decouple the three players in the MVC model, which keeps designs clear and flexible.
* The Adapter Pattern can be used to adapt a new model to an existing view and controller.
* MVC has been adapted to the web.
* There are many web MVC frameworks with various adaptations of the MVC pattern to fit the client/server application structure.