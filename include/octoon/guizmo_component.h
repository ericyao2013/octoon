#ifndef OCTOON_GUIZMO_COMPONENT_H_
#define OCTOON_GUIZMO_COMPONENT_H_

#include <octoon/game_component.h>
#include <octoon/ui/imgui.h>

namespace octoon
{
	class OCTOON_EXPORT GuizmoComponent : public GameComponent
	{
		OctoonDeclareSubClass(GuizmoComponent, GameComponent)
	public:
		GuizmoComponent() noexcept;
		GuizmoComponent(const GameObjectPtr& camera) noexcept;

		octoon::GameComponentPtr clone() const noexcept override;

	private:
		void onActivate() noexcept override;
		void onDeactivate() noexcept override;

		void onGui() noexcept override;

	private:
		GameObjectPtr camera_;
		imgui::guizmo::Operation op_;
	};
}

#endif