# Decorator
The Decorator Pattern attaches additional responsibilities to an object dynamically. Decorators provide a flexible alternative to subclassing for extending functionality. ![alt text](image.png)
![alt text](image-1.png)

It give objects new responsibilities without making any code changes to the underlying classes. Objects can be decorated at any time, so we can decorate objects dynamically at runtime with as many decorators as we like. Here `we’re using inheritance to achieve the type matching, but we aren’t using inheritance to get behavior.` The behavior comes in through the composition of decorators with the base components as well as other decorators. `We typically create decorators by using other patterns like Factory and Builder so that the creation of the concrete component with its decorator is “well encapsulated” and doesn’t lead to problems.`

* Inheritance is one form of extension, but not necessarily the best way to achieve flexibility in our designs.
* In our designs we should allow behavior to be extended without the need to modify existing code.
* Composition and delegation can often be used to add new behaviors at runtime.
* The Decorator Pattern provides an alternative to subclassing for extending behavior.
* The Decorator Pattern involves a set of decorator classes that are used to wrap concrete components.
* Decorator classes mirror the type of the components they decorate. (In fact, they are the same type as the components they decorate, either through inheritance or interface implementation.)
* Decorators change the behavior of their components by adding new functionality before and/or after (or even in place of) method calls to the component.
* You can wrap a component with any number of decorators.
* Decorators are typically transparent to the client of the component—that is, unless the client is relying on the component’s concrete type.
* Decorators can result in many small objects in our design, and overuse can be complex.