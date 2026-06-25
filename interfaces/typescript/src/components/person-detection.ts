// GENERATED FROM interfaces/schema — DO NOT EDIT
// Source: PersonDetectedEvent.schema.json, PersonDetectionStatusResult.schema.json
// Generator: scripts/generate.ts

import { z } from "zod";

// ─── Shared type definitions ($defs) ─────────────────────────────

/**
 * Status of a RoIS component.
 * 
 * Maps to RoIS_Common::Component_Status in the IDL.
 * 
 * UNINITIALIZED: Component has not been initialized.
 * READY: Component is ready to operate.
 * BUSY: Component is currently processing.
 * WARNING: Component is operational but has a warning condition.
 * ERROR: Component has encountered an error.
 */

export const ComponentStatusSchema = z.enum(["UNINITIALIZED", "READY", "BUSY", "WARNING", "ERROR"]);
export type ComponentStatus = z.infer<typeof ComponentStatusSchema>;


/**
 * Event payload for Person_Detection::Event::person_detected.
 * 
 * Maps to the person_detected event in PersonDetection.xml.
 * 
 * Attributes:
 *     timestamp: ISO 8601 datetime when the detection was measured.
 *     number: Number of detected persons in the current frame/observation.
 */

export const PersonDetectedEventSchema = z.object({
  timestamp: z.string(), // Time when measured
  number: z.number().int(), // Number of detected persons
}).strict();
export type PersonDetectedEvent = z.infer<typeof PersonDetectedEventSchema>;

/**
 * Result model for PersonDetection component_status query.
 * 
 * Attributes:
 *     status: Current status of the PersonDetection component.
 */

export const PersonDetectionStatusResultSchema = z.object({
  status: ComponentStatusSchema,
}).strict();
export type PersonDetectionStatusResult = z.infer<typeof PersonDetectionStatusResultSchema>;
