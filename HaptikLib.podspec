#
#  Be sure to run `pod spec lint HaptikLib.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see http://docs.cocoapods.org/specification.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|

  s.name         = "HaptikLib"
  s.version      = "0.0.1"
  s.summary      = "Say goodbye to App Fatigue. Instantly enable 40+ chatbots across various daily tasks"

  s.description  = <<-DESC
                The mobile app industry is about a decade old but publishers are still trying to figure out hacks to improve user retention. App fatigue is not just a theory any more: 60% of apps are uninstalled within the first week. The Haptik Assistant SDK enables a layer of daily use chatbots in any mobile app. Instantly provide a lot more reasons for users to keep using your app. Monetize through transactions and the Haptik ad platform.
                   DESC

  s.homepage     = "https://github.com/hellohaptik/HaptikLib-iOS"

  s.license      = { :type => "MIT", :file => "LICENSE" }

  s.author           = { 'Simranjot Singh' => 'simranjyot@haptik.co' }
  s.social_media_url   = "http://twitter.com/iamsimranjot"

  s.ios.deployment_target = '9.0'
  s.requires_arc = true

  s.source       = { :git => "https://github.com/hellohaptik/HaptikLib-iOS.git", :tag => s.version.to_s }

  s.vendored_frameworks = 'Framework/HaptikLib.framework'

  s.dependency    'PINRemoteImage', '3.0.0-beta.13'
  s.dependency    'PINRemoteImage/WebP', '3.0.0-beta.13'

end
