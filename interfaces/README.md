# OpenRoIS Interfaces

Transport-independent [RoIS Framework 2.0](https://www.omg.org/spec/RoIS/2.0/Beta2)
interface types, generated across three language stacks from a single source.

## Structure

```
interfaces/
├── python/      # Source of truth — Pydantic models (hand-authored)
├── schema/      # Canonical JSON Schema wire contract (generated from Python)
├── csharp/      # C# types for Unity (generated from schema)
└── typescript/  # TypeScript types for web (generated from schema)
```

## Pipeline

```
Python (Pydantic) ──export_schema.py──► JSON Schema ──Generator──► C#
                                         │                  └──generate.ts──► TypeScript
                                         └── manifest.json (module→file map)
```

1. **Author** Pydantic models in `python/src/openrois/interfaces/`
2. **Export** to JSON Schema: `cd python && python scripts/export_schema.py`
3. **Generate** C#: `cd csharp/scripts/Generator && dotnet run -- ../../schema`
4. **Generate** TypeScript: `cd typescript && npx tsx scripts/generate.ts`

The schema drift test (`python/tests/test_schema_drift.py`) verifies committed
schemas match Pydantic output. C# and TypeScript are never hand-written.

## Packages

| Package | Language | Version | Status |
|---------|----------|---------|--------|
| `openrois-interfaces` | Python 3.11+ | 0.1.0a1 | Source of truth |
| `OpenRoIS.Interfaces` | C# (netstandard2.1) | 0.1.0-alpha.1 | Generated |
| `@openrois/interfaces` | TypeScript (ESM) | 0.1.0-alpha.1 | Generated |

## Components

Typed models for 3 of 17 basic RoIS components are implemented:

| Component | Operations | Stacks |
|-----------|-----------|--------|
| PersonDetection | Event: `person_detected` | Python, C#, TS |
| Navigation | Command: `set_parameter`; Query: `get_parameter`; Event: `reached_target` | Python, C#, TS |
| SystemInformation | Query: `robot_position`, `engine_status` | Python, C#, TS |

Remaining components will be added in M4 (mock components) and M11 (full library).

## License

Apache 2.0. See each package's `LICENSE` file.