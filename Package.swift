// swift-tools-version:5.5
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "SAP-SPM-POC",
    platforms: [.iOS(.v15)],
    products: [
        .library(
            name: "SAP-SPM-POC",
            targets: ["SAP-SPM-POC"]),
    ],
    dependencies: [
        .package(name: "cloud-sdk-ios", url: "https://github.com/SAP/cloud-sdk-ios.git", from: "9.2.7"),
    ],
    
    targets: [
        // Targets are the basic building blocks of a package. A target can define a module or a test suite.
        // Targets can depend on other targets in this package, and on products in packages this package depends on.
        .target(
            name: "SAP-SPM-POC",
            dependencies: ["cloud-sdk-ios"]),
    ]
)
