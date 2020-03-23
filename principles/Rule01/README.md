[TOC]

## The Single Resposibility Principle

### Outline

- Definition

q:经典定义是什么?
>A class should only have a single responsibility, that is, only changes to one part of the software's specification should be able to affect the specification of the class.
>
>martin本人给的另一种类似定义：
>The Single Responsibility Principle (SRP) states that each software module should have one and only one reason to change. 

我们下面进入更深度的灵魂拷问

q:类的职责是什么？reason to change指的又是什么?
>
1.类的职责在于其核心行为。那么什么又是核心行为呢？我们参考第二个问题
2.reason to change的理解没有那么容易，字面意思很简单，就是对函数行为的变化。但是结合SRP来说，此处对reason的理解，就是responsibilty或者aspect
>
>我们再多一点理解，one reason, one aspect, one responsibility其实就是描述类，函数的核心逻辑只能有一个。

q:如何进一步理解？
>第二篇参考文献给出了作者自己进一步的阐述，
>
>When you write a software module, you want to make sure that when changes are requested, those changes can only originate from a single person
这里的single person可以理解为一个类或者函数
>
>作者举了这样的一个例子：
ceo管理cfo,coo,cto.
cfo的核心行为是，calculatePay
coo的核心行为是，reportHours
cto的核心行为是，save
假如我们没有按照SRP的设计原则，那么我们可能设计一个如下的类：
>
>显而易见的是，如果我们修改calculatePay和save这两个方法，肯定会影响cfo和cto。不幸的是，这个员工其实是coo，但是上面两个方法在实现的时候都出示问题。那么，老板会因为cfo和cto没有做好的事情，而把cfo开除掉。如果coo的实现贯彻了SRP原则，那么coo不会被开除

```java
public class Employee {
  public Money calculatePay();
  public void save();
  public String reportHours();
}
```


q:简单来说的意义是什么?
>The reason it is important to keep a class focused on a single concern is that it makes the class more robust

- Advantage
  - 类的复杂性降低
  - 变更引起的风险降低
  - 可读性变强
  - 可维护性提高

- Disadvantage
  - 系统的复杂性提高
  - 提出"responsibility" or "reason to change"来衡量接口或者类的设计是否优良，但是这二者就不可度量，需要依赖项目

- warning
  - 对于class design，不尽然
  - 对于function design，没问题

### Practice


参考<br>
[Single-responsibility principle](https://en.wikipedia.org/wiki/Single-responsibility_principle)<br>
[The Single Responsibility Principle](https://blog.cleancoder.com/uncle-bob/2014/05/08/SingleReponsibilityPrinciple.html)