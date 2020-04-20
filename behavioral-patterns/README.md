[TOC]

## Behavioral Patterns

### Base

q:Behavioral Patterns的动机是什么？主要想解决什么问题？
>Behavioral patterns are concerned with algorithms and and the assignment of responsibilities between objects.
>
>简言之，行为模式关注算法的实现，以及对象之间责任的划分，即再需要多个对象联合完成一件事情时，应该采取什么的策略来为每个对象指定对应的工作。

q:behavioral patterns主要讲了哪几方面的内容
- Behavioral class patterns
- Behavioral object patterns
- Patterns of communication between them

q:behavioral patterns的优点是什么?
- These patterns characterize complex control flow that's difficult to follow at run-time.
- They shift your focus away from flow of control to let you concentrate just on the way objects are interconnected
>简言之，行为模式的优点还是对于复杂控制流的处理上。

q:behavioral class patterns有哪些分类？
>Behavioral class patterns use inheritance to distribute behavior between classes.
>
>注意，这句话很重要。对行为有了描述，其实本质来说一个对象或者类的行为，就是它的方法。那么一个类到底应该提供哪些方法，当多个类协作完成一个任务时，方法之间的分配又应该如何呢？我相信行为模式主要是用来解决这个问题。
- Template Method
- Interpreter

q:behavioral object patterns又有哪些分类?
>Behavioral object patterns use object composition rather than inheritance.
>
>对比类之间的行为分发，其实行为模式对于我们应该使用继承还是组合也给了一种观点。只不过这个观点是从类和对象的角度去说的。
- Mediator
- Chain of Responsibility
- Observer
- Other behavioral object patterns are concerned with encapsulating behavior in an object and delegating requests to it
  - Strategy
  - Command
  - State
  - Visitor
  - Iterator