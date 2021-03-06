#ifndef OCTOON_GRAPHICS_SYSTEM_H_
#define OCTOON_GRAPHICS_SYSTEM_H_

#include <octoon/graphics/graphics_types.h>
#include <octoon/runtime/singleton.h>

namespace octoon
{
	namespace graphics
	{
		class OCTOON_EXPORT GraphicsSystem final
		{
			OctoonDeclareSingleton(GraphicsSystem)
		public:
			GraphicsSystem() noexcept;
			~GraphicsSystem() noexcept;

			void close() noexcept;

			GraphicsDevicePtr createDevice(const GraphicsDeviceDesc& desc) noexcept;

		private:
			GraphicsSystem(const GraphicsSystem&) = delete;
			GraphicsSystem& operator=(const GraphicsSystem&) = delete;

		private:
			GraphicsDeviceWeaks _devices;
		};
	}
}

#endif