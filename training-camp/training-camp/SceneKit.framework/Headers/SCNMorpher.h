//
//  SCNMorpher.h
//
//  Copyright (c) 2013-2017 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SceneKit/SCNAnimation.h>

NS_ASSUME_NONNULL_BEGIN

@class SCNGeometry;

typedef NS_ENUM(NSInteger, SCNMorpherCalculationMode) {
    SCNMorpherCalculationModeNormalized = 0, // (1 - w0 - w1 - ...) * BaseMesh + w0 * Target0 + w1 * Target1 + ...
    SCNMorpherCalculationModeAdditive   = 1  // BaseMesh + w0 * Target0 + w1 * Target1 + ...
};

/*!
 @class SCNMorpher
 @abstract SCNMorpher controls the deformation of morphed geometries
 */
API_AVAILABLE(macos(10.9))
@interface SCNMorpher : NSObject <SCNAnimatable, NSSecureCoding>

/*!
 @property targets
 @abstract Specifies the morph targets as an array of SCNGeometry.
 @discussion The target geometries must have the same number of entries in their geometry sources and the same topology as the base geometry.
 */
@property(nonatomic, copy) NSArray<SCNGeometry *> *targets;

/*!
 @method setWeight:forTargetAtIndex:
 @abstract Sets the weight for the target at the specified index. Animatable implicitly or explicitly with the keyPath "weights[index]" or "weights[targetName]" (targetName is the name of the target geometry).
 */
- (void)setWeight:(CGFloat)weight forTargetAtIndex:(NSUInteger)targetIndex;

/*!
 @method weightForTargetAtIndex:
 @abstract Retrieves the weight for the target at the specified index.
 */
- (CGFloat)weightForTargetAtIndex:(NSUInteger)targetIndex;

/*!
 @property calculationMode
 @abstract Specifies how the morph result is calculated by the receiver. Defaults to SCNMorpherCalculationModeNormalized.
 */
@property(nonatomic) SCNMorpherCalculationMode calculationMode;

/*!
 @property weights
 @abstract Access to all the weights of all the targets.
 */
@property (nonatomic, retain) NSArray<NSNumber *> *weights API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0), watchos(4.0));

/*!
 @property unifiesNormals
 @abstract When set to YES the normals are not morphed but are recomputed after morphing the vertex instead. When set to NO, the morpher will morph the normals if the geometry targets have normals. Defaults to NO.
 */
@property BOOL unifiesNormals API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0), watchos(4.0));

/*!
 @property channelTargetWeights
 @abstract Specifies the number of target shapes per channel.
 @discussion Can be NULL if every channel contains only one target shape. Defaults to NULL.
 @seealso channelTargetWeights
 */
@property (nonatomic, retain, nullable) NSArray<NSNumber *> *channelTargetCounts API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0), watchos(4.0));

/*!
 @property channelTargetWeights
 @abstract the weights at which the (in-between) target shapes are placed (0..1).
 @discussion Can be NULL if every channel contains only one target shape.
 */
@property (nonatomic, retain, nullable) NSArray<NSNumber *> *channelTargetWeights API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0), watchos(4.0));

@end

NS_ASSUME_NONNULL_END
