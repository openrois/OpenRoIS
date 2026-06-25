# openrois-interfaces

![Python](https://img.shields.io/badge/Python-3.12+-3776AB?logo=python&logoColor=white)

Transport-independent [RoIS Framework 2.0](https://www.omg.org/spec/RoIS/2.0/Beta2)
interface types for Python.

This package is the **single source of truth** for all OpenRoIS types.
Pydantic models authored here are exported to JSON Schema
(`interfaces/schema/`) and generated into
[C#](../csharp/) and [TypeScript](../typescript/).

## Installation

```bash
pip install openrois-interfaces
```

## Usage

```python
from openrois.interfaces import ReturnCode, Result, BusAdapter

# Construct a RoIS Result
result = Result(name="number", data_type_ref="int", value="3")

# Type-safe enum
code = ReturnCode.OK

# Implement the BusAdapter contract
class MyAdapter(BusAdapter):
    async def discover(self, request): ...
    async def invoke(self, request): ...
    async def query(self, request): ...
    async def subscribe(self, request, sink): ...
```

## Module structure

| Module | Contents |
|--------|----------|
| `openrois.interfaces.hri` | Core HRI types: `ReturnCode`, `Result`, `Parameter`, `Argument`, `CommandUnit`, `CommandUnitSequence` |
| `openrois.interfaces.common` | `ComponentStatus`, `StreamStatus` |
| `openrois.interfaces.service` | `CompletedStatus`, `ErrorType`, `CompletedEvent`, `NotifyErrorEvent`, `NotifyEventPayload` |
| `openrois.interfaces.profiles` | Component profile schema models |
| `openrois.interfaces.bus` | `BusAdapter` protocol, request/response models, `EventEnvelope`, error classes |
| `openrois.interfaces.components` | Per-component typed message models |

## Development

```bash
pip install -e ".[dev]"
pytest                    # run tests
mypy src/                 # type-check
ruff check src/           # lint
python scripts/export_schema.py  # regenerate JSON Schema
```