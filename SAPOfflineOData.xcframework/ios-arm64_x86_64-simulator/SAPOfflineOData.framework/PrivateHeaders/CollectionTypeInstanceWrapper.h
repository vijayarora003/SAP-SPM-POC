//
//  CollectionTypeInstanceWrapper.h
//  SAPOfflineOData
//
//  Copyright © 2017 SAP SE or an SAP affiliate company. All rights reserved.
//
//  No part of this publication may be reproduced or transmitted in any form or for any purpose
//  without the express permission of SAP SE.  The information contained herein may be changed
//  without prior notice.
//

#import "TypeInstanceWrapper.h"
#import "CollectionItemTypeWrapper.h"

#if __cplusplus

namespace lodata
{
    class CollectionTypeInstance;
}

#endif

@interface CollectionTypeInstanceWrapper : OBJ_WRAPPER_BASE

#if __cplusplus
-( instancetype ) initWithCppInstance: ( const lodata::CollectionTypeInstance * ) collectionPropertyValue;
- (const lodata::CollectionTypeInstance *) getCppInstance;
#endif

-( const char * ) unsafeGetJsonValue;

- ( NSMutableArray * ) getSimpleValueList;
- ( NSMutableArray * ) getEnumValueList;
- ( NSMutableArray * ) getComplexTypeInstanceList;
- (bool) isDecoded;
@end
