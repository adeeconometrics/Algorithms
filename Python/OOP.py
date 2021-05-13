class Base:
    def __init__(self) -> None:
        print("Base class is called.")

    def method(self, a: int) -> None:
        print("prints {0} from Base class".format(a))

    def __del__(self) -> None:
        print("Base destructor is called")


class Derived(Base):
    def __init__(self) -> None:
        print("Derived constructor is called.")

    def method(self, a: int) -> None:
        print("prints {0} from Derived class".format(a))

    def __del__(self):
        print("Derived destructor is called")


if __name__ == '__main__':
    base = Base()
    derived = Derived()

    base.method(3)
    derived.method(3)