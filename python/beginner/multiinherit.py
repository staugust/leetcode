"""
test C3 Method resolution method.
Note: For python3.x, no more classic class, all classes are new style class,
      which means that every class has base class, except class object.
"""
class Base(object):
    def __init__(self):
        self.x = 1


class MA(Base):
    def __init__(self):
        self.x = 2


class MB(Base):
    def __init__(self):
        self.x = 3


class Final(MB, MA, Base):
    def __init__(self):
        Base.__init__(self)
        super(Final,self).__init__()

class D:
    pass

class E:
    pass

class F:
    pass

class C(D,F):
    pass


class B(E,D):
    pass


class A(B,C):
    pass


class TA:
    pass

class TB(TA):
    pass

class TC(TB,TA):
    pass

class ZZ:
    pass

if __name__ == '__main__':
    var = Final()
    print(var.x)
    print(Final.mro())
    print(A.mro())
    print(TC.mro())
    print(object.mro())
    print(ZZ.mro())