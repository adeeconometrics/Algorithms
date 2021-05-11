# import numpy as np
from typing import Union


def avg(_list: list) -> Union[float, int]:
    return sum(_list) / len(_list)
