### 题目说明  
我们提供一个类：

class FooBar {
  public void foo() {
    for (int i = 0; i < n; i++) {
      print("foo");
    }
  }

  public void bar() {
    for (int i = 0; i < n; i++) {
      print("bar");
    }
  }
}
两个不同的线程将会共用一个 FooBar 实例。其中一个线程将会调用 foo() 方法，另一个线程将会调用 bar() 方法。

请设计修改程序，以确保 "foobar" 被输出 n 次。

 

示例 1:

输入: n = 1
输出: "foobar"
解释: 这里有两个线程被异步启动。其中一个调用 foo() 方法, 另一个调用 bar() 方法，"foobar" 将被输出一次。

#### 题解一  
```
class FooBar {
    private int n;
    private final Semephore SemaphoreFoo=new Semephore(0);//一个Semephore允许一个许可
    private final Semephore SemephoreBar=new Semephore(0);
    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            
        	// printFoo.run() outputs "foo". Do not change or remove this line.
        	printFoo.run();
            SemephoreBar.release();//释放SemephoreBar
            SemephoreFoo.acquire();//请求SemephoreFoo的许可，如果没有释放该信号量，则等待
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            SemephoreBar.acquire();
            // printBar.run() outputs "bar". Do not change or remove this line.
        	printBar.run();
            SemephoreFoo.release();
        }
    }
}
```

#### 利用valotile关键字  
```
class FooBar {
    private int n;
    private volatile int lock = 0;

    public FooBar(int n) {
        this.n = n;
        this.lock = 2*n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            while(this.lock%2 == 1){
            }
            // printFoo.run() outputs "foo". Do not change or remove this line.
        	printFoo.run();
            this.lock--;
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            while(this.lock%2 == 0){

            }
            // printBar.run() outputs "bar". Do not change or remove this line.
        	printBar.run();
            this.lock--;
        }
    }
}


```
