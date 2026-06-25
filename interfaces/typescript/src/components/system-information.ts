// GENERATED FROM interfaces/schema — DO NOT EDIT
// Source: SystemInformationEngineStatusResult.schema.json, SystemInformationRobotPositionResult.schema.json
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

export const RoISIdentifierListSchema = z.array(z.string());
export type RoISIdentifierList = z.infer<typeof RoISIdentifierListSchema>;


/**
 * Result payload for System_Information::Query::engine_status.
 * 
 * Maps to the engine_status query in SystemInformation.xml.
 * 
 * Attributes:
 *     status: Current component status of the engine.
 *     operable_time: List of ISO 8601 datetimes representing operable periods.
 */

export const SystemInformationEngineStatusResultSchema = z.object({
  status: ComponentStatusSchema, // Engine component status
  operable_time: z.array(z.string()), // Operable time periods
}).strict();
export type SystemInformationEngineStatusResult = z.infer<typeof SystemInformationEngineStatusResultSchema>;

/**
 * Result payload for System_Information::Query::robot_position.
 * 
 * Maps to the robot_position query in SystemInformation.xml.
 * 
 * Attributes:
 *     timestamp: ISO 8601 datetime when the position was measured.
 *     robot_ref: List of robot identifiers in the position data.
 *     position_data: Positional/measurement data (RoLo Data sequence as strings).
 */

export const SystemInformationRobotPositionResultSchema = z.object({
  timestamp: z.string(), // Time when measured
  robot_ref: RoISIdentifierListSchema, // List of robot IDs
  position_data: z.array(z.string()), // Position data (RoLo Data sequence)
}).strict();
export type SystemInformationRobotPositionResult = z.infer<typeof SystemInformationRobotPositionResultSchema>;
