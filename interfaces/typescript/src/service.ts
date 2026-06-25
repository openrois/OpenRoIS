// GENERATED FROM interfaces/schema — DO NOT EDIT
// Source: CompletedEvent.schema.json, CompletedStatus.schema.json, ErrorType.schema.json, NotifyErrorEvent.schema.json, NotifyEventPayload.schema.json
// Generator: scripts/generate.ts

import { z } from "zod";

// ─── Shared type definitions ($defs) ─────────────────────────────

/**
 * Status of a completed command execution.
 * 
 * Maps to RoIS_Service::Completed_Status in the IDL.
 * 
 * OK: Command completed successfully.
 * ERROR: Command completed with an error.
 * ABORT: Command was aborted.
 * OUT_OF_RESOURCES: Command failed due to resource exhaustion.
 * TIMEOUT: Command timed out before completion.
 */

export const CompletedStatusSchema = z.enum(["OK", "ERROR", "ABORT", "OUT_OF_RESOURCES", "TIMEOUT"]);
export type CompletedStatus = z.infer<typeof CompletedStatusSchema>;

/**
 * Classification of error notifications.
 * 
 * Maps to RoIS_Service::ErrorType in the IDL.
 * 
 * ENGINE_INTERNAL_ERROR: Error originating from the HRI Engine itself.
 * COMPONENT_INTERNAL_ERROR: Error originating from a component.
 * COMPONENT_NOT_RESPONDING: A component failed to respond within timeout.
 * USER_DEFINED_ERROR: Application-specific error.
 */

export const ErrorTypeSchema = z.enum(["ENGINE_INTERNAL_ERROR", "COMPONENT_INTERNAL_ERROR", "COMPONENT_NOT_RESPONDING", "USER_DEFINED_ERROR"]);
export type ErrorType = z.infer<typeof ErrorTypeSchema>;


/**
 * Event payload for ServiceApplicationBase::completed.
 * 
 * Attributes:
 *     command_id: The command identifier that completed.
 *     status: The completion status.
 */

export const CompletedEventSchema = z.object({
  command_id: z.string(),
  status: CompletedStatusSchema,
}).strict();
export type CompletedEvent = z.infer<typeof CompletedEventSchema>;

/**
 * Event payload for ServiceApplicationBase::notify_error.
 * 
 * Attributes:
 *     error_id: Unique identifier for this error instance.
 *     error_type: Classification of the error.
 */

export const NotifyErrorEventSchema = z.object({
  error_id: z.string(),
  error_type: ErrorTypeSchema,
}).strict();
export type NotifyErrorEvent = z.infer<typeof NotifyErrorEventSchema>;

/**
 * Event payload for ServiceApplicationBase::notify_event.
 * 
 * Attributes:
 *     event_id: Unique identifier for this event occurrence.
 *     event_type: The type of event (e.g., 'person_detected', 'face_localized').
 *     subscribe_id: The subscription identifier that this event matches.
 *     expire: ISO 8601 datetime when this event expires, or empty if no expiry.
 */

export const NotifyEventPayloadSchema = z.object({
  event_id: z.string(),
  event_type: z.string(),
  subscribe_id: z.string(),
  expire: z.string().default(""),
}).strict();
export type NotifyEventPayload = z.infer<typeof NotifyEventPayloadSchema>;
