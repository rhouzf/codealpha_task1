from _typeshed import Incomplete

from influxdb_client.domain.view_properties import ViewProperties

class GaugeViewProperties(ViewProperties):
    openapi_types: Incomplete
    attribute_map: Incomplete
    discriminator: Incomplete
    def __init__(
        self,
        type: Incomplete | None = None,
        queries: Incomplete | None = None,
        colors: Incomplete | None = None,
        shape: Incomplete | None = None,
        note: Incomplete | None = None,
        show_note_when_empty: Incomplete | None = None,
        prefix: Incomplete | None = None,
        tick_prefix: Incomplete | None = None,
        suffix: Incomplete | None = None,
        tick_suffix: Incomplete | None = None,
        decimal_places: Incomplete | None = None,
    ) -> None: ...
    @property
    def type(self): ...
    @type.setter
    def type(self, type) -> None: ...
    @property
    def queries(self): ...
    @queries.setter
    def queries(self, queries) -> None: ...
    @property
    def colors(self): ...
    @colors.setter
    def colors(self, colors) -> None: ...
    @property
    def shape(self): ...
    @shape.setter
    def shape(self, shape) -> None: ...
    @property
    def note(self): ...
    @note.setter
    def note(self, note) -> None: ...
    @property
    def show_note_when_empty(self): ...
    @show_note_when_empty.setter
    def show_note_when_empty(self, show_note_when_empty) -> None: ...
    @property
    def prefix(self): ...
    @prefix.setter
    def prefix(self, prefix) -> None: ...
    @property
    def tick_prefix(self): ...
    @tick_prefix.setter
    def tick_prefix(self, tick_prefix) -> None: ...
    @property
    def suffix(self): ...
    @suffix.setter
    def suffix(self, suffix) -> None: ...
    @property
    def tick_suffix(self): ...
    @tick_suffix.setter
    def tick_suffix(self, tick_suffix) -> None: ...
    @property
    def decimal_places(self): ...
    @decimal_places.setter
    def decimal_places(self, decimal_places) -> None: ...
    def to_dict(self): ...
    def to_str(self): ...
    def __eq__(self, other): ...
    def __ne__(self, other): ...