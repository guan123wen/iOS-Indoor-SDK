//  Copyright (c) 2014 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTOrientedLineSegment.h"

///-----------------------------------------
/// @name Constants
///-----------------------------------------
#pragma mark Constants

/** Describes the type of the linear object. */
typedef enum : NSUInteger {
    ESTLocationLinearObjectTypeDoor,
    ESTLocationLinearObjectTypeWindow,
} ESTLocationLinearObjectType;

/**
 * Represents an object in location which position can be described by a line segment.
 * Typical examples are doors, windows, internal partition walls etc.
 */
@interface ESTLocationLinearObject : NSObject

#pragma mark Properties
///-----------------------------------------
/// @name Properties
///-----------------------------------------

/** Type of the object. */
@property (nonatomic, assign, readonly) ESTLocationLinearObjectType type;
/**
 * Coordinates of the object in form of an oriented line segment.
 * Orientation typically represent direction toward center of the location, perpendicular to the line segment.
 */
@property (nonatomic, strong, readonly) ESTOrientedLineSegment *linePosition;

#pragma mark Creating and Initializing Points
///------------------------------------------------
/// @name Creating and Initializing Linear Objects
///------------------------------------------------

/**
 * Returns a new linear object.
 *
 * @param type A type of the linear object.
 * @param linePosition Coordinates of the object in form of an oriented line segment
 * @return A linear object initialized with linePosition and type.
 */
- (instancetype)initWithType:(ESTLocationLinearObjectType)type
                linePosition:(ESTOrientedLineSegment *)linePosition;

/**
 * Returns a new linear object based on the given linear object.
 *
 * @param point A linear object.
 * @return An linear object initialized with linearObject.type and linearObject.linePosition
 */
+ (instancetype)linearObjectWithLinearObject:(ESTLocationLinearObject *)linearObject;

#pragma mark Operations on linear object
///-----------------------------------------
/// @name Operations on linear object
///-----------------------------------------

/**
* Translates the linear object by a given vector (dX, dY) and returns a new linear object.
*
* @param dX Value of translation on X axis.
* @param dY Value of translation on Y axis.
* @return A new linear object translated by (dX, dY).
*/
- (instancetype)linearObjectTranslatedByDX:(double)dX
                                        dY:(double)dY;

#pragma mark Serialization
///-----------------------------------------
/// @name Serialization
///-----------------------------------------

/**
* Deserializes a linear object from `NSDictionary`.
*
* @param dict NSDictionary to deserialize from.
* @return A linear object created from NSDictionary.
*/
+ (ESTLocationLinearObject *)linearObjectFromDictionary:(NSDictionary *)dict;

/**
* Serializes the linear object to `NSDictionary`.
*
* @return A linear object representation in NSDictionary.
*/
- (NSDictionary *)toDictionary;

#pragma mark Identifying and Comparing Objects
///-----------------------------------------
/// @name Identifying and Comparing Objects
///-----------------------------------------

/**
* Returns a boolean value that indicates whether given linear object is equal to this one.
*
* @param other The object to be compared to this linear object. May be nil.
* @return YES if linear objects are equal, otherwise NO.
*/
- (BOOL)isEqual:(id)other;

/** @see isEqual: */
- (BOOL)isEqualToLinearObject:(ESTLocationLinearObject *)object;

/** Returns an integer that can be used as a table address in a hash table structure. */
- (NSUInteger)hash;

@end


