[TOC]
## Singleton

### Intent

q:rt?
>Ensure a class only has one instance, and provide a global point of access to it.
>
>这里有一点需要特别注意的是，global point of access，即提供一个全局入口。一个自然的想法是，我直接提供一个全局对象不就好了。
只要client不要再定义全局对象，即可保证全局唯一。
显然，这样的做法有明显的缺点就是，全局对象的作用域没有得到限制，也就是正常全局对象的缺点

### Motivation
q:rt?
>It's important for some classes to have exactly one instance.
A better solution is to make the class itself responsible for keeping track of
its sole instance. The class can ensure that no other instance can be created
(by intercepting requests to create new objects), and it can provide a way to
access the instance. This is the Singleton pattern.

### Applicability
q:rt?
Use the Singleton pattern when
1. there must be exactly one instance of a class, and it must be accessible
to clients from a well-known access point.
2. when the sole instance should be extensible by subclassing, and clients
should be able to use an extended instance without modifying their code.

这里特别注意，dp原文对于派生能力也给出了要求。

参考<br>
[Thread-Safe Initialization of Data](https://www.modernescpp.com/index.php/thread-safe-initialization-of-data)

### Structure

<img width="700"  src="img/singeleton.png"/>

### Participants

- singleton
  - defines an Instance operation that lets clients access its unique
instance. Instance is a class operation (that is, a class method
in Smalltalk and a static member function in C++).
  - may be responsible for creating its own unique instance.

### Collaborations

Clients access a Singleton instance solely through Singleton's Instance
operation.

### Consequences

The Singleton pattern has several benefits:
- Controlled access to sole instance.
- Reduced name space.
- Permits refinement of operations and representation.
- Permits a variable number of instances.
- More flexible than class operations.

Moreover, static member functions in C++ are never virtual, so subclasses
can't override them polymorphically.