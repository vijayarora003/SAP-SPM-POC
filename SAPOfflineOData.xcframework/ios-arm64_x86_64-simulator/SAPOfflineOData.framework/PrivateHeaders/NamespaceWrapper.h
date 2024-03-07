//
//  NamespaceWrapper.h
//  SAPOfflineOData
//
//  Copyright © 2023 SAP SE or an SAP affiliate company. All rights reserved.
//
//  No part of this publication may be reproduced or transmitted in any form or for any purpose
//  without the express permission of SAP SE.  The information contained herein may be changed
//  without prior notice.
//

#import "MemoryTrackerBase.h"

#if __cplusplus

namespace lodata
{
    class Namespace;
}

#endif

@interface NamespaceWrapper : OBJ_WRAPPER_BASE

#if __cplusplus
- (instancetype) initWithCppInstance: (const lodata::Namespace * ) cppNamespace;
#endif

- (NSString *) getName;

- (uint32_t) getID;

- (BOOL) isClientOnly;

@end

