//
//  ARHitTestResult.h
//  ARKit
//
//  Copyright © 2017 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGGeometry.h>
#import <simd/simd.h>

@class ARAnchor;

/**
 Option set of hit-test result types.
 */
API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(macos, watchos, tvos)
typedef NS_OPTIONS(NSUInteger, ARHitTestResultType) {
    /** Result type from intersecting the nearest feature point. */
    ARHitTestResultTypeFeaturePoint              = (1 << 0),
    
    /** Result type from intersecting a horizontal plane estimate, determined for the current frame. */
    ARHitTestResultTypeEstimatedHorizontalPlane  = (1 << 1),
    
    /** Result type from intersecting with an existing plane anchor. */
    ARHitTestResultTypeExistingPlane             = (1 << 3),
    
    /** Result type from intersecting with an existing plane anchor, taking into account the plane's extent. */
    ARHitTestResultTypeExistingPlaneUsingExtent  = (1 << 4),
} NS_SWIFT_NAME(ARHitTestResult.ResultType);

NS_ASSUME_NONNULL_BEGIN

/**
 A result of an intersection found during a hit-test.
 */
API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(macos, watchos, tvos)
@interface ARHitTestResult : NSObject

/**
 The type of the hit-test result.
 */
@property (nonatomic, readonly) ARHitTestResultType type;

/**
 The distance from the camera to the intersection in meters.
 */
@property (nonatomic, readonly) CGFloat distance;

/**
 The transformation matrix that defines the intersection's rotation, translation and scale
 relative to the anchor or nearest feature point.
 */
@property (nonatomic, readonly) matrix_float4x4 localTransform;

/**
 The transformation matrix that defines the intersection's rotation, translation and scale
 relative to the world.
 */
@property (nonatomic, readonly) matrix_float4x4 worldTransform;

/**
 The anchor that the hit-test intersected.
 
 @discussion An anchor will only be provided for existing plane result types.
 */
@property (nonatomic, strong, nullable, readonly) ARAnchor *anchor;

@end


@interface ARHitTestResult (Unavailable)

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
