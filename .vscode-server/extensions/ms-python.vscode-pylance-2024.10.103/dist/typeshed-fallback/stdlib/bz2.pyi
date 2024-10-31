import _compression
import sys
from _compression import BaseStream
from _typeshed import ReadableBuffer, StrOrBytesPath, WriteableBuffer
from collections.abc import Iterable
from typing import IO, Any, Literal, Protocol, SupportsIndex, TextIO, final, overload
from typing_extensions import Self, TypeAlias

__all__ = ["BZ2File", "BZ2Compressor", "BZ2Decompressor", "open", "compress", "decompress"]

# The following attributes and methods are optional:
# def fileno(self) -> int: ...
# def close(self) -> object: ...
class _ReadableFileobj(_compression._Reader, Protocol): ...

class _WritableFileobj(Protocol):
    def write(self, b: bytes, /) -> object: ...
    # The following attributes and methods are optional:
    # def fileno(self) -> int: ...
    # def close(self) -> object: ...

def compress(data: ReadableBuffer, compresslevel: int = 9) -> bytes: ...
def decompress(data: ReadableBuffer) -> bytes: ...

_ReadBinaryMode: TypeAlias = Literal["", "r", "rb"]
_WriteBinaryMode: TypeAlias = Literal["w", "wb", "x", "xb", "a", "ab"]
_ReadTextMode: TypeAlias = Literal["rt"]
_WriteTextMode: TypeAlias = Literal["wt", "xt", "at"]

@overload
def open(
    filename: _ReadableFileobj,
    mode: _ReadBinaryMode = "rb",
    compresslevel: int = 9,
    encoding: None = None,
    errors: None = None,
    newline: None = None,
) -> BZ2File: ...
@overload
def open(
    filename: _ReadableFileobj,
    mode: _ReadTextMode,
    compresslevel: int = 9,
    encoding: str | None = None,
    errors: str | None = None,
    newline: str | None = None,
) -> TextIO: ...
@overload
def open(
    filename: _WritableFileobj,
    mode: _WriteBinaryMode,
    compresslevel: int = 9,
    encoding: None = None,
    errors: None = None,
    newline: None = None,
) -> BZ2File: ...
@overload
def open(
    filename: _WritableFileobj,
    mode: _WriteTextMode,
    compresslevel: int = 9,
    encoding: str | None = None,
    errors: str | None = None,
    newline: str | None = None,
) -> TextIO: ...
@overload
def open(
    filename: StrOrBytesPath,
    mode: _ReadBinaryMode | _WriteBinaryMode = "rb",
    compresslevel: int = 9,
    encoding: None = None,
    errors: None = None,
    newline: None = None,
) -> BZ2File: ...
@overload
def open(
    filename: StrOrBytesPath,
    mode: _ReadTextMode | _WriteTextMode,
    compresslevel: int = 9,
    encoding: str | None = None,
    errors: str | None = None,
    newline: str | None = None,
) -> TextIO: ...
@overload
def open(
    filename: StrOrBytesPath | _ReadableFileobj | _WritableFileobj,
    mode: str,
    compresslevel: int = 9,
    encoding: str | None = None,
    errors: str | None = None,
    newline: str | None = None,
) -> BZ2File | TextIO: ...

class BZ2File(BaseStream, IO[bytes]):
    def __enter__(self) -> Self: ...
    if sys.version_info >= (3, 9):
        @overload
        def __init__(self, filename: _WritableFileobj, mode: _WriteBinaryMode, *, compresslevel: int = 9) -> None: ...
        @overload
        def __init__(self, filename: _ReadableFileobj, mode: _ReadBinaryMode = "r", *, compresslevel: int = 9) -> None: ...
        @overload
        def __init__(
            self, filename: StrOrBytesPath, mode: _ReadBinaryMode | _WriteBinaryMode = "r", *, compresslevel: int = 9
        ) -> None: ...
    else:
        @overload
        def __init__(
            self, filename: _WritableFileobj, mode: _WriteBinaryMode, buffering: Any | None = None, compresslevel: int = 9
        ) -> None: ...
        @overload
        def __init__(
            self, filename: _ReadableFileobj, mode: _ReadBinaryMode = "r", buffering: Any | None = None, compresslevel: int = 9
        ) -> None: ...
        @overload
        def __init__(
            self,
            filename: StrOrBytesPath,
            mode: _ReadBinaryMode | _WriteBinaryMode = "r",
            buffering: Any | None = None,
            compresslevel: int = 9,
        ) -> None: ...

    def read(self, size: int | None = -1) -> bytes: ...
    def read1(self, size: int = -1) -> bytes: ...
    def readline(self, size: SupportsIndex = -1) -> bytes: ...  # type: ignore[override]
    def readinto(self, b: WriteableBuffer) -> int: ...
    def readlines(self, size: SupportsIndex = -1) -> list[bytes]: ...
    def seek(self, offset: int, whence: int = 0) -> int: ...
    def write(self, data: ReadableBuffer) -> int: ...
    def writelines(self, seq: Iterable[ReadableBuffer]) -> None: ...

@final
class BZ2Compressor:
    def __init__(self, compresslevel: int = 9) -> None: ...
    def compress(self, data: ReadableBuffer, /) -> bytes: ...
    def flush(self) -> bytes: ...

@final
class BZ2Decompressor:
    def decompress(self, data: ReadableBuffer, max_length: int = -1) -> bytes: ...
    @property
    def eof(self) -> bool: ...
    @property
    def needs_input(self) -> bool: ...
    @property
    def unused_data(self) -> bytes: ...
