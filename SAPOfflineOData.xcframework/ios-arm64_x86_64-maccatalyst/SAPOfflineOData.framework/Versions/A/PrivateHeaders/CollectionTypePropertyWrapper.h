//
//  CollectionTypePropertyWrapper.h
//  SAPOfflineOData
//
//  Copyright © 2017 SAP SE or an SAP affiliate company. All rights reserved.
//
//  No part of this publication may be reproduced or transmitted in any form or for any purpose
//  without the express permission of SAP SE.  The information contained herein may be changed
//  without prior notice.
//

#import "EnumerationDef.h"
#import "MemoryTrackerBase.h"

#if __cplusplus

namespace lodata
{
	class CollectionTypeProperty;
}

#endif
@class CollectionItemTypeWrapper;

@interface CollectionTypePropertyWrapper : OBJ_WRAPPER_BASE

#if __cplusplus
- (instancetype) initWithCppInstance: (const lodata::CollectionTypeProperty *) prop;
- (const lodata::CollectionTypeProperty *) getCppInstance;
#endif

- (CollectionItemTypeWrapper*) getCollectionItemTypeWrapper;
- (NSString *) getName;
- (bool) getIsNullable;
- (EdmTypeObjC) getItemType;

@end