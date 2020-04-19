[TOC]

## Observer

### 实践

- demo-01

这是一个错误的实践，但是我保留了这个demo的原因在于，这个demo犯了一些值得思考的错误》
1. 编译通不过。
```cpp
demo-01/mcall_subscriber.cc:8:38: error: member access into incomplete type 'dp::Publisher'
  const PerformanceData& data = p_sub->GetData();
```
2. 对于Update接口理解有误。编译之所以通不过，根本原因在于对于update接口理解有误，subscriber并不是通过update接口来获取
publisher的state，update接口的语义只是publisher用来消息通知subsriber，数据更新了。subscriber可以进行同步。
3. 为什么update接口不能在消息提醒的同时，进行数据同步。确实，我一开始也是这么理解的，原因在于，相互引用的存在，导致subscriber/publisher必须有一个采用forward declaration，这会间接导致incomplete type. 从而不能对其成员进行访问。
我想这也是为什么publisher还是要保留一个指向subscriber的根本原因，因为实际的操作不允许通过update接口来获取状态。
4. EventLoop的逻辑没有问题，但是这需要publisher和subscriber单独启动一个程序，逻辑上也确实是这样的，但是在我目前的测试程序里还无法实现。
