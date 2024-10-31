from _typeshed import Incomplete

class BuilderConfig:
    openapi_types: Incomplete
    attribute_map: Incomplete
    discriminator: Incomplete
    def __init__(
        self,
        buckets: Incomplete | None = None,
        tags: Incomplete | None = None,
        functions: Incomplete | None = None,
        aggregate_window: Incomplete | None = None,
    ) -> None: ...
    @property
    def buckets(self): ...
    @buckets.setter
    def buckets(self, buckets) -> None: ...
    @property
    def tags(self): ...
    @tags.setter
    def tags(self, tags) -> None: ...
    @property
    def functions(self): ...
    @functions.setter
    def functions(self, functions) -> None: ...
    @property
    def aggregate_window(self): ...
    @aggregate_window.setter
    def aggregate_window(self, aggregate_window) -> None: ...
    def to_dict(self): ...
    def to_str(self): ...
    def __eq__(self, other): ...
    def __ne__(self, other): ...
