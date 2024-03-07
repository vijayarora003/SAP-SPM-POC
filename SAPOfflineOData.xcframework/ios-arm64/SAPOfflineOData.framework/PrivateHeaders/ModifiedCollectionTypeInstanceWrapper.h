//
//  ModifiedCollectionTypeInstanceWrapper.h
//  SAPOfflineOData
//
//  Copyright © 2017 SAP SE or an SAP affiliate company. All rights reserved.
//
//  No part of this publication may be reproduced or transmitted in any form or for any purpose
//  without the express permission of SAP SE.  The information contained herein may be changed
//  without prior notice.
//
#import "MemoryTrackerBase.h"

#if __cplusplus
namespace lodata
{
    class CollectionTypeInstance;
}
#endif

@class ArenaAllocatorWrapper;
@class CollectionTypePropertyWrapper;
@class EnumValueWrapper;
@class ModifiedComplexTypeInstanceWrapper;
@class ValueWrapper;

@interface ModifiedCollectionTypeInstanceWrapper : OBJ_WRAPPER_BASE

#if __cplusplus
- (lodata::CollectionTypeInstance *) getCppInstance;
#endif

- (instancetype) init: (const CollectionTypePropertyWrapper *) collectionPropertyWrapper allocator: (ArenaAllocatorWrapper *) allocator;

- (void) addSimpleValue: (ValueWrapper *) value;
- (void) addEnumValue: (EnumValueWrapper *) value;
- (void) addComplexInstance: (ModifiedComplexTypeInstanceWrapper *) value;


@end
