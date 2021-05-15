from abc import ABC, abstractmethod


class Abstract(ABC):
    @abstractmethod
    def abstract_method(self):
        pass


class Base(Abstract):
    def __init__(self) -> None:
        print("Base class is called.")

    def method(self, a: int) -> None:
        print("prints {0} from Base class".format(a))

    def abstract_method(self):
        print("abstract_method is called from Base class.")

    def __del__(self) -> None:
        print("Base destructor is called")


class Derived(Base):
    def __init__(self) -> None:
        print("Derived constructor is called.")

    def method(self, a: int) -> None:
        print("prints {0} from Derived class".format(a))

    def abstract_method(self) -> None:
        print("abstract_method is called from Derived class")

    def __del__(self):
        print("Derived destructor is called")


def functon(obj: Abstract) -> None:
    return obj.abstract_method()


if __name__ == '__main__':
    base = Base()
    derived = Derived()

    base.method(3)
    derived.method(3)