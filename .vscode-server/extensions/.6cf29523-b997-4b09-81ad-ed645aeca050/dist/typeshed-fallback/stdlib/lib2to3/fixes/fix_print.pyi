from _typeshed import Incomplete
from typing import ClassVar, Literal

from .. import fixer_base

parend_expr: Incomplete

class FixPrint(fixer_base.BaseFix):
    BM_compatible: ClassVar[Literal[True]]
    PATTERN: ClassVar[str]
    def transform(self, node, results): ...
    def add_kwarg(self, l_nodes, s_kwd, n_expr) -> None: ...
