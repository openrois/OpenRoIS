# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/2.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Added

- ESM package with subpath exports: `.`, `/hri`, `/common`, `/service`, `/profiles`, `/bus`, `/components`.
- Generate `@openrois/interfaces` TypeScript package from 38 JSON Schema files in `interfaces/schema/`.
- Emit zod schemas + inferred types for all core HRI, Common, Service, Profile, Bus, and component models.
- Emit generated component models for `PersonDetection`, `Navigation`, and `SystemInformation`.
- Hand-write `BusAdapter` interface, `EventSink` type, `BusAdapterError` and `ComponentNotFoundError` error classes.

[unreleased]: https://github.com/openrois/openrois/compare/main...HEAD