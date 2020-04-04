[TOC]
## factory method

### Intent

q:策略模式的定义是什么?如何理解
>Define an interface for creating an object, but let subclasses decide which class to instantiate. Factory Method lets a class defer instantiation to subclasses.
>
>就目前理解而言，我觉得为创建对象单独定义一个接口，这句话我理解更深一点。

### Motivation(why)

q:rt?
>作者在文章中先是举了一个例子，
特定Document和特定应用相关，所以，对于Application而言，不可能预测到底哪一个Document将被实例化。
Application只知道，一个新的文档何时被创建，但是不知道具体是哪一个Document将被创建。
>
>factory method提供了一个办法是，它封装了哪一个Document将被创建出来的信息，并将该信息从框架中分离出来。
具体来说，就是将这部分信息封装到Application的子类当中。
>
>这是作者举的例子。我自己的看法则是工厂模式的优点，结合base-demo来说，CrateMaze采用硬编码的方式，不够灵活。
工厂模式则是把对象的创建过程，从CrateMaze当中解耦出去了。
即使用者不用关心对象的创建过程，因为工厂模式将对象的创建过程解耦出去，使用者只用关心拿到对象之后的应用逻辑即可
>
>这又牵扯另一个问题，对象的创建调用构造函数即可，为什么需要解耦呢。两个方面：
1. Maze这一类对象的创建过程相对复杂。不是一个构造函数能解决的。构造函数只能把对象初始化为0，并不是一个真正可以调用的对象
2. 直接使用对象构造函数是硬编码，如果不用这个对象，代码需要修改。如果改用工厂方法则代码有可重用性。

### Structure

<img width="700"  src="img/factory-method.png"/>

### Participants

- Product (Document)
  - defines the interface of objects the factory method creates.
- ConcreteProduct (MyDocument)
  - implements the Product interface.
- Creator (Application)
  - declares the factory method,which returns an object of type Product.Creator may also define a default implementation of the factory method that returns a default ConcreteProduct object.
- ConcreteCreator (MyApplication)
  - overrides the factory method to return an instance of a ConcreteProduct.

### Consequences

从常规理解角度，
- 优点：将与特定应用有关的类代码，从调用代码中解耦。调用者不关心对象具体的创建过程。这样可以保证调用者代码的重用性。
- 缺点：仅仅为了创建一个特定的ConcreateProduct就不得不创建ConcreateCreator

另外两种效果
- Provides hooks for subclasses.
- Connects parallel class hierarchies.

### Implementation

原则：**用一个独立的操作创建对象，这样子类才能重定义他们的创建方式**

下面是一些建议：
- c++中的factory method通常都是virtual function，并且常常是pure virtual function.(ec::Rule34，实践中也是建议多写pure virtuao function)
- 采用lazy initialization手法(NVI实现)
  - Instead of creating the concreate product in the constructor(constructor merely initializes it to 0)
  - The assesor returns the product.
- 使用模板以避免创建子类

下面我们看一个例子：
```cpp
// product.h
#ifndef PRODUCT_H_
#define PRODUCT_H_

namespace dp {

class Product {
 public:
  virtual ~Product() {}

 public:
  virtual void DoSomething() = 0;
};

} // namespace dp

#endif // PRODUCT_H_

// concreate_product.h
#ifndef CONCREATE_PRODUCT_H_
#define CONCREATE_PRODUCT_H_

#include "product.h"

namespace dp {

class ConcreateProduct : public Product {
 public:
  ConcreateProduct() {}

 public:
  void DoSomething() override;
};

};

#endif // CONCREATE_PRODUCT_H_

// creator.h
#ifndef CREATOR_H_
#define CREATOR_H_

#include "product.h"

namespace dp {

#ifndef CREATOR_H_
#define CREATOR_H_

#include "product.h"

namespace dp {

class Creator {
 public:
  Creator() : p_product_(nullptr) {}
  virtual ~Creator() {
    if(p_product_) {
      delete p_product_;
    }
  }

  Product* GetProduct() {
    if(p_product_)
      return p_product_;

    p_product_ = MakeProduct();
    return p_product_;
  }

 private:
  virtual Product* MakeProduct() = 0;

 private:
  Product* p_product_;
};

} // namespace dp

#endif // CREATOR_H_


} // namespace dp

#endif // CREATOR_H_

// concreate_creator.h
#ifndef CONCREATE_CREATOR_H_
#define CONCREATE_CREATOR_H_

#include "creator.h"

namespace dp {

class ConcreateCreator : public Creator {
 public:
  ConcreateCreator() : Creator() {}

 private:
  Product* MakeProduct() override;
};

} // namespace dp

#endif // CONCREATE_CREATOR_H_

// main.cc
#include "concreate_creator.h"
using namespace dp;

int main() {
  ConcreateCreator ctor;
  Product* p_product = ctor.GetProduct();

  p_product->DoSomething();

  return 0;
}
```

上面这个实现，主要用了以下手法
- NVI
- lazy initialization

当然，这其中NVI的使用非常关键，基类定义了定义调用的时机，但是派生类重写了private vf，进行了不同的实现。这刚好和creator, concrate_creator语义相符。creator定义调用调用的时机，concreate_creator给出自己的实现。

不过，我有一个疑问在于，灵活性我认为没有保留，确实构造过程的复杂性(采用lazy initialization)通过一个操作进行了封装，这没有质疑的。但是，业务代码多少还是需要知道concreate_product才能进行创建。或者说，提高了灵活性，这么说准确的。

```cpp
Product* p_product = new ConcreateProduct();
p_product->DoSomething();

// 这么实现，没用工厂方法。好像也行，但是如果使用lazy initialization后，在main.cc当中的构造过程就相对复杂，且灵活性不够。
// 使用工厂方法之后，main.cc确实不需要关注lazy initialization如何实现，对象的构造过程细节做到了屏蔽。
```

上面实现的一个问题是，如果仅仅需要一个concreate_product，也需要提供一个concreate_creator.
此时可以采用模板的方法来避免频繁定义creator子类

```cpp
// product.h
// concreate_product.h

// creator.h
#ifndef CREATOR_H_
#define CREATOR_H_

#include "product.h"

namespace dp {

class Creator {
 public:
  Creator() : p_product_(nullptr) {}
  virtual ~Creator() {}

  Product* GetProduct() {
    if(p_product_)
      return p_product_;

    p_product_ = MakeProduct();
    return p_product_;
  }

 private:
  virtual Product* MakeProduct() = 0;

 private:
  Product* p_product_;
};

} // namespace dp

#endif // CREATOR_H_


// standard_creator.h
#ifndef STANDARD_CREATOR_H_
#define STANDARD_CREATOR_H_

#include "creator.h"

namespace dp {

template<class TheProduct>
class StandardCreator : public Creator {
 public:
  StandardCreator() : Creator() {}

 private:
  Product* MakeProduct() {
    return new TheProduct();
  }
};

} // namespace dp

#endif // STANDARD_CREATOR_H_

```

下面用smart pointer给出一版实现
```cpp
// creator.h
#ifndef CREATOR_H_
#define CREATOR_H_

#include <memory>
#include "product.h"

namespace dp {

class Creator {
 public:
  virtual ~Creator() {}
  typedef std::shared_ptr<Product> ProductPtr;

  ProductPtr GetProduct() {
    if(product_ptr_)
      return product_ptr_;

    product_ptr_ = MakeProduct();
    return product_ptr_;
  }

 private:
  virtual ProductPtr MakeProduct() = 0;

 private:
  ProductPtr product_ptr_;
};

} // namespace dp

#endif // CREATOR_H_


// standard_creator.h
#ifndef STANDARD_CREATOR_H_
#define STANDARD_CREATOR_H_

#include "creator.h"

namespace dp {

template<class TheProduct>
class StandardCreator : public Creator {
 private:
  ProductPtr MakeProduct() {
    return std::make_shared<TheProduct>();
  }
};

} // namespace dp

#endif // STANDARD_CREATOR_H_

// main.cc
#include "concreate_product.h"
#include "standard_creator.h"

using namespace dp;

int main() {
  std::shared_ptr<Creator> ctor_ptr = std::make_shared< StandardCreator<ConcreateProduct> >();
  std::shared_ptr<Product> product_ptr = ctor_ptr->GetProduct();
  product_ptr->DoSomething();

  return 0;
}
```

### suggestions from zen of design patterns

看了下设计模式之禅对于工厂方法的介绍，讲述的比较简单，深度赶不上这里，但是讲的还比较实用。设计模式之禅对于工厂方法的讲述
主要是说提供一个方法用来构造对象，从而封装构造对象的过程。但是，设计模式在讲工厂方法的时候，还谈到了工厂方法的其余作用，
对于base-demo的改写就是个非常好的例子。

- 简单工厂方法

考虑上面的代码的问题，对于每一个concreate_product，都需要一个concreate_creator，即使我们采用模板的方式。
也至少需要定义一个standard_creator<TheProduct>

简单工厂的思路是，考虑到大部分工厂方法对于对象的构造比较简单，很多都是直接在动态内存上开辟对象。所以，放弃对于
不同concreate_product构造的扩展性，不提供虚函数让派生类进行重写。但是，泛型的能力是支持的。

结论，对于几种工厂方法的区别，一定要从本质去判断，而不要从表面类的构造去判断
- 泛型。提供通用性
- 虚函数。提供灵活性

区别：
- 正常工厂。提供泛型和虚函数的能力。对于不同的product，可以定义不同的creator。不同的creator可以具有不同的MakeProduct逻辑。
- 简单工厂。提供泛型能力，但不提供虚函数能力。对于不同的product，定义同一个creator template，当然此时看上去好像是不同的creator，但实际不是。因为他们MakeProduct的逻辑都是一样的。
- 普通工厂。严格来说，没有这种定义。不提供泛型，也不提供函数。

```cpp
// product.h
// concreate_product.h

// creator.h
// 1.不提供虚函数
// 2.工厂方法声明为static
#ifndef CREATOR_H_
#define CREATOR_H_

#include <memory>
#include "product.h"

namespace dp {

template<class TheProduct>
class Creator {
 public:
  Creator() {}
  typedef std::shared_ptr<Product> ProductPtr;

  static ProductPtr GetProduct() {
    return MakeProduct();
  }

 private:
  static ProductPtr MakeProduct() {
    return std::make_shared<TheProduct>();
  }
};

} // namespace dp

#endif // CREATOR_H_

// main.cc
#include "concreate_product.h"
#include "creator.h"

using namespace dp;

int main() {
  std::shared_ptr<Product> product_ptr = Creator<ConcreateProduct>::GetProduct();
  product_ptr->DoSomething();

  return 0;
}
```

下面我们看个例子，定义一组二元算子，实现计算操作。
我们先来看cpp的实现，考虑到构造的过程基本一致，所以我采用简单工厂

```cpp
// binary_computing.h
#ifndef BINARY_COMPUTING_H_
#define BINARY_COMPUTING_H_

namespace dp {

class BinaryComputing {
 public:
  BinaryComputing() : left_(0), right_(0) {}
  BinaryComputing(int l, int r) : left_(l), right_(r) {}
  virtual ~BinaryComputing() {}

  virtual int DoComputing() const = 0;

 protected:
  int left_;
  int right_;
};

} // namespace dp

#endif // BINARY_COMPUTING

// add_computing.h
#ifndef ADD_COMPUTING_H_
#define ADD_COMPUTING_H_

#include "binary_computing.h"

namespace dp {

class AddComputing : public BinaryComputing {
 public:
  AddComputing() : BinaryComputing() {}
  AddComputing(int l, int r) : BinaryComputing(l, r) {}

  int DoComputing() const override;

};

} // namespace dp

#endif // ADD_COMPUTING_H_

// minus_computing.h
#ifndef MINUS_COMPUTING_H_
#define MINUS_COMPUTING_H_

#include "binary_computing.h"

namespace dp {

class MinusComputing : public BinaryComputing {
 public:
  MinusComputing() : BinaryComputing() {}
  MinusComputing(int l, int r) : BinaryComputing(l, r) {}

  int DoComputing() const override;

};

} // namespace dp

#endif // MINUS_COMPUTING_H_

// computing_factory.h
#ifndef COMPUTING_FACTORY_H_
#define COMPUTING_FACTORY_H_

#include <memory>

namespace dp {

template<class TheComputing>
class ComputingFactory {
 public:
  typedef std::shared_ptr<TheComputing> ComputingPtr;
  ComputingFactory() {}

  static ComputingPtr GetComputing(int left, int right) {
    return MakeComputing(left, right);
  }

 private:
  static ComputingPtr MakeComputing(int left, int right) {
    return std::make_shared<TheComputing>(left, right);
  }

};

} // namespace dp

#endif // COMPUTING_FACTORY_H_
```

**通过cpp这个例子，我们可以发现，工厂方法还有特别重要的一个特点是，构造具体对象的参数，需要工厂方法提供**。

下面，我们来看lua的例子，有一些trick
1. 首先，lua当中没有abstract class，当然[Lua设计模式](http://allran.github.io/2014/01/26/2014-01-26-lua-design-patterns/)这篇文章当中由类似的模拟做法。但是我不打算采用abstract class的方式。因为本来也没有继承保证(无法提供数据的代码复用)，所以我就直接在各种product当中定义自己的数据即可。
2. 其次，因为lua只是模拟，做到神似即可。这个要把握住，lua最佳实践告诉我们，不要把lua写的比cpp还fuza

```lua
-- add_computing.lua
local _M = {}

_M.name = "add_computing"

function _M.New(l, r)
  local o = {
    left = l,
    right = r
  }
  setmetatable(o, {__index = _M})

  return o
end

function _M.DoComputing(self)
  return self.left + self.right
end

return _M

-- minus_computing.lua
local _M = {}

_M.name = "minus_computing"

function _M.New(l, r)
  local o = {
    left = l,
    right =r
  }
  setmetatable(o, {__index = _M})

  return o
end

function _M.DoComputing(self)
  return self.left - self.right
end

return _M

-- computing_factory.lua
local AddComputing = require "add_computing"
local MinusComputing = require "minus_computing"

local _M = {}

function _M.New(ct)
  local o = {
    computing_type = ct
  }
  setmetatable(o, {__index = _M})

  return o
end

function _M.GetComputing(self, l, r)
  if self.computing_type == AddComputing.name then
    return AddComputing.New(l, r)
  elseif self.computing_type == MinusComputing.name then
    return MinusComputing.New(l, r)
  end
end

return _M

-- simple_computing_factory.lua
local AddComputing = require "add_computing"
local MinusComputing = require "minus_computing"

local _M = {}

function _M.GetComputing(computing_type, l, r)
  if computing_type == AddComputing.name then
    return AddComputing.New(l, r)
  elseif computing_type == MinusComputing.name then
    return MinusComputing.New(l, r)
  end
end

return _M

-- main.lua
local ComputingFactory = require "computing_factory"
local SimpleComputingFactory = require "simple_computing_factory"

local AddComputing = require "add_computing"
local MinusComputing = require "minus_computing"

local function test_factory()
  local AddComputingFactory = ComputingFactory.New(AddComputing.name)
  local add_obj = AddComputingFactory:GetComputing(3, 4)
  print(add_obj:DoComputing())

  local MinusComputingFactory = ComputingFactory.New(MinusComputing.name)
  local add_obj = MinusComputingFactory:GetComputing(3, 4)
  print(add_obj:DoComputing())
end

local function test_simple_factory()
  local add_obj = SimpleComputingFactory.GetComputing(AddComputing.name, 3, 4)
  print(add_obj:DoComputing())

  local minus_obj = SimpleComputingFactory.GetComputing(MinusComputing.name, 3, 4)
  print(minus_obj:DoComputing())
end

test_factory()

test_simple_factory()
```

看了lua的实现，一些细节需要注意：
1. simple_factory在使用时，看似没有像factory使用时先定义对应product的creator，而是直接用一个factory进行构造。但是，本质上，它不能算是simple_factory. 因为simple_factory的实现，具备了不同product，提供不同MakeProduct的能力。
2. 注意，不同语言的使用，一定要灵活，不要教条。特别是对于lua而言，很多地方做到“神似”即可

### demo

1. demo-01, ordinary pointer实现
2. demo-02, ordinary pointer + template实现
3. demo-03, smart pointer + template实现
4. demo-04, base-demo的factory-method实现
5. demo-05, 不提供虚函数
6. demo-06, 提供了一个实践的例子，对于工厂方法模式的理解更加深刻，并且对几种工厂模式的区别也更加清晰

我们仔细对比这几个demo的实现，可以发现一些规律通用性，灵活性上的一些差异。我不太认同设计模式之禅当中的提法，很为gof的设计模式也没有提到这样的分类，我们可以从代码通用性，灵活性的角度来理解
1. demo-01/demo-02/demo-03提供了泛型，虚函数的能力。通用性和灵活性都是最好的。
2. demo-05，只提供泛型，不提供虚函数。代码灵活性不好，因为所有creator的MakeProduct方法都是一样的。
3. 最极端的一种方法，就是类似于base-demo当的maze和maze_game，没有通用性，也没有泛型的支持。但是确实封装了对于对象的构造过程
