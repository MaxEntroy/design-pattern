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

### demo

1. demo-01, ordinary pointer实现
2. demo-02, ordinary pointer + template实现
3. demo-03, smart pointer + template实现
4. demo-04, base-demo的factory-method实现