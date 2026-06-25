# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/2.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Changed

- Upgrade generator to resolve `$ref`-to-simple-type inline (PEP 695 named type
  aliases). Simple-type `$defs` (primitives like `RoISIdentifier`, `Integer`)
  are now inlined as `z.string()`/`z.number().int()` instead of referencing
  non-existent schema variables. Complex-type `$defs` (arrays, unions, objects)
  are still emitted as separate zod schemas.
- Remove hardcoded `ArgumentList` and `CommandUnitSequenceItem` type aliases
  from the `hri` module (now auto-generated from `$defs`).
- Regenerate all source files from updated JSON Schema (named type aliases
  via PEP 695 `$defs`/`$ref`).

## [0.1.0-alpha.1] - 2026-06-20

### Added

- Generate `@openrois/interfaces` TypeScript package from 38 JSON Schema files in `interfaces/schema/`.
- Emit zod schemas + inferred types for all core HRI, Common, Service, Profile, Bus, and component models.
- Hand-write `BusAdapter` interface, `EventSink` type, `BusAdapterError` and `ComponentNotFoundError` error classes.
- ESM package with subpath exports: `.`, `/hri`, `/common`, `/service`, `/profiles`, `/bus`, `/components`.
- Custom generator (`scripts/generate.ts`) handling `$defs`, `$ref`, `anyOf` unions, recursive types, enums, defaults, and `additionalProperties: false`.

[unreleased]: https://github.com/openrois/openrois/compare/main...HEAD
[0.1.0-alpha.1]: https://github.com/openrois/openrois/releases/tag/v0.1.0-alpha.1