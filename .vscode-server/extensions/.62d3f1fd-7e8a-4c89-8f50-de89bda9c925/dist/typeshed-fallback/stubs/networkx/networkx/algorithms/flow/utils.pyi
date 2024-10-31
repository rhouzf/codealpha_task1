from _typeshed import Incomplete

from networkx.utils.backends import _dispatch

class CurrentEdge:
    def __init__(self, edges) -> None: ...
    def get(self): ...
    def move_to_next(self) -> None: ...

class Level:
    active: Incomplete
    inactive: Incomplete
    def __init__(self) -> None: ...

class GlobalRelabelThreshold:
    def __init__(self, n, m, freq) -> None: ...
    def add_work(self, work) -> None: ...
    def is_reached(self): ...
    def clear_work(self) -> None: ...

@_dispatch
def build_residual_network(G, capacity): ...
@_dispatch
def detect_unboundedness(R, s, t) -> None: ...
@_dispatch
def build_flow_dict(G, R): ...
