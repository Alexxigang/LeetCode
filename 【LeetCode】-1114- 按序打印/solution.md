### 题目描述  
我们提供了一个类：
```
public class Foo {
  public void one() { print("one"); }
  public void two() { print("two"); }
  public void three() { print("three"); }
}

```
三个不同的线程将会共用一个 Foo 实例。

线程 A 将会调用 one() 方法
线程 B 将会调用 two() 方法
线程 C 将会调用 three() 方法
请设计修改程序，以确保 two() 方法在 one() 方法之后被执行，three() 方法在 two() 方法之后被执行。

 

示例 1:

输入: [1,2,3]
输出: "onetwothree"
解释: 
有三个线程会被异步启动。
输入 [1,2,3] 表示线程 A 将会调用 one() 方法，线程 B 将会调用 two() 方法，线程 C 将会调用 three() 方法。
正确的输出是 "onetwothree"。
#### 题解一  
```
class Foo {

private int flag=1;//控制执行顺序的标志

public Foo() {
    
}

public void first(Runnable printFirst) throws InterruptedException {
    
    synchronized (this) //线程同步关键词
	{
		while(flag!=1)
			this.wait();  //条件不满足就等待
    
    // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        
        flag=2;
		this.notifyAll();	//通知其他线程执行			
	}			
}

public void second(Runnable printSecond) throws InterruptedException {
    synchronized (this) 
	{
		while(flag!=2)
			this.wait();
    
    // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
        flag=3;
		this.notifyAll();				
	}			
}

public void third(Runnable printThird) throws InterruptedException {
    synchronized (this) 
	{
		while(flag!=3)
			this.wait();
    
    // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
        flag=1;
		this.notifyAll();				
	}			
}
}

```

#### 题解二  （没有通过测试）
```
class Foo {
    private CountDownLatch countDownLatchA;//设置两个栅栏锁
    private CountDownLatch countDownLatchB;
    public Foo() {
        countDownLatchA=new CountDownLatch(1);//一个栅栏锁锁一个线程
        countDownLatchB=new CountDownLatch(1);
    }

    public void first(Runnable printFirst) throws InterruptedException {
        
        // printFirst.run() outputs "first". Do not change or remove this line.
        
        printFirst.run();
        countDownLatchA.countDown();//countDownLatchA锁计数器减一为0，通知countDownLatchA已经完成了一个线程了
    }

    public void second(Runnable printSecond) throws InterruptedException {
        
        // printSecond.run() outputs "second". Do not change or remove this line.
        countDownLatchA.await();//等待countDownLatchA所有线程完成
        printSecond.run();
        countDownLatchB.countDown();
    }

    public void third(Runnable printThird) throws InterruptedException {
        
        // printThird.run() outputs "third". Do not change or remove this line.
        countDownLatchB.await();
        printThird.run();
        
    }
}
```
