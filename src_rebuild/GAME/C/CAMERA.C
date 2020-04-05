#include "THISDUST.H"
#include "CAMERA.H"

VECTOR CameraPos =
{ 4294967251, 4294967125, 4294967171, 0 };

VECTOR camera_position =
{ 0, 4294966916, 0, 0 };

MATRIX face_camera_work =
{ { { 4096, 0, 0 }, { 0, 4096, 0 }, { 0, 0, 4096 } }, { 0, 0, 0 } };

// decompiled code
// original method signature: 
// void /*$ra*/ InitCamera(struct _PLAYER *lp /*$s0*/)
 // line 422, offset 0x0001f5f4
	/* begin block 1 */
		// Start line: 423
		// Start offset: 0x0001F5F4
		// Variables:
	// 		struct SVECTOR boxDisp; // stack offset -16

		/* begin block 1.1 */
			// Start line: 428
			// Start offset: 0x0001F61C
		/* end block 1.1 */
		// End offset: 0x0001F61C
		// End Line: 428

		/* begin block 1.2 */
			// Start line: 441
			// Start offset: 0x0001F6AC
			// Variables:
		// 		struct _CAR_DATA *lcp; // $a0
		/* end block 1.2 */
		// End offset: 0x0001F6AC
		// End Line: 441

		/* begin block 1.3 */
			// Start line: 454
			// Start offset: 0x0001F794
			// Variables:
		// 		struct _EVENT *event; // $a1
		/* end block 1.3 */
		// End offset: 0x0001F794
		// End Line: 455
	/* end block 1 */
	// End offset: 0x0001FA20
	// End Line: 544

	/* begin block 2 */
		// Start line: 844
	/* end block 2 */
	// End Line: 845

void InitCamera(_PLAYER *lp)
{
	UNIMPLEMENTED();
	/*
	byte bVar1;
	undefined4 in_zero;
	undefined4 in_at;
	int iVar2;
	CAR_COSMETICS *pCVar3;
	_EVENT *p_Var4;
	undefined4 local_10;
	uint local_c;

	if (events.cameraEvent == (_EVENT *)0x0) {
		if (NumPlayers == 2) {
			lp->cameraView = '\x02';
		}
		paddCamera = Pads[lp->padid].mapped;
		if ((NoPlayerControl != 0) || (gInGameCutsceneActive != 0)) {
			lp->cameraView = cameraview;
		}
		iVar2 = (int)lp->cameraCarId;
		if (iVar2 < 0) {
			if (iVar2 < -1) {
				p_Var4 = events.track[-2 - iVar2];
				basePos[0] = (p_Var4->position).vx;
				basePos[1] = -(p_Var4->position).vy;
				basePos[2] = (p_Var4->position).vz;
				baseDir = (int)p_Var4->rotation + 0x400U & 0xfff;
			}
			else {
				basePos[0] = lp->pos[0];
				basePos[1] = lp->pos[1];
				basePos[2] = lp->pos[2];
				DAT_000aca9c = lp->pos[3];
				baseDir = lp->dir;
			}
		}
		else {
			setCopControlWord(2, 0, *(undefined4 *)car_data[iVar2].hd.where.m);
			setCopControlWord(2, 0x800, *(undefined4 *)(car_data[iVar2].hd.where.m + 2));
			setCopControlWord(2, 0x1000, *(undefined4 *)(car_data[iVar2].hd.where.m + 4));
			setCopControlWord(2, 0x1800, *(undefined4 *)(car_data[iVar2].hd.where.m + 6));
			setCopControlWord(2, 0x2000, *(undefined4 *)(car_data[iVar2].hd.where.m + 8));
			setCopControlWord(2, 0x2800, car_data[iVar2].hd.where.t[0]);
			setCopControlWord(2, 0x3000, car_data[iVar2].hd.where.t[1]);
			setCopControlWord(2, 0x3800, car_data[iVar2].hd.where.t[2]);
			pCVar3 = car_data[iVar2].ap.carCos;
			local_10 = CONCAT22(-(pCVar3->cog).vy, -(pCVar3->cog).vx);
			local_c = local_c & 0xffff0000 | (uint)(ushort)-(pCVar3->cog).vz;
			setCopReg(2, in_zero, local_10);
			setCopReg(2, in_at, local_c);
			copFunction(2, 0x480012);
			basePos[0] = getCopReg(2, 0x19);
			basePos[1] = getCopReg(2, 0x1a);
			basePos[2] = getCopReg(2, 0x1b);
			baseDir = car_data[iVar2].hd.direction;
		}
		bVar1 = lp->cameraView;
		if (bVar1 == 1) {
			if ((NoPlayerControl == 0) && (gInGameCutsceneActive == 0)) {
				tracking_car = '\x01';
			}
			PlaceCameraAtLocation(lp, 1);
		}
		else {
			if (bVar1 < 2) {
				if (bVar1 == 0) {
					if (FrameCnt == 0) {
						lp->cameraDist = 1000;
						gCameraAngle = 0x800;
						CameraPos.vx = -0x2d;
						CameraPos.vy = -0xab;
						CameraPos.vz = -0x7d;
					}
					else {
						PlaceCameraFollowCar(lp);
					}
				}
			}
			else {
				if (bVar1 == 2) {
					if (bTannerSitting == 0) {
						PlaceCameraInCar(lp, 0);
					}
					else {
						PlaceCameraAtLocation(lp, 0);
					}
				}
				else {
					if (bVar1 == 5) {
						if (NoPlayerControl == 0) {
							if (gInGameCutsceneActive == 0) {
								tracking_car = '\x01';
							}
							TargetCar = 0;
						}
						PlaceCameraAtLocation(lp, 0);
					}
				}
			}
		}
		if ((((gCurrentMissionNumber == 0x16) && ((lp->cameraPos).vx < 0)) &&
			(iVar2 = (lp->cameraPos).vz, iVar2 < 0xc1c47)) && (700000 < iVar2)) {
			SpecialCamera(SPECIAL_CAMERA_SET, 0);
		}
		camera_position.vx = (lp->cameraPos).vx;
		camera_position.vy = (lp->cameraPos).vy;
		camera_position.vz = (lp->cameraPos).vz;
		CameraCar = (int)lp->cameraCarId;
		lp->snd_cam_ang = (int)camera_angle.vy;
	}
	else {
		BuildWorldMatrix();
	}
	return;
	*/
}



// decompiled code
// original method signature: 
// void /*$ra*/ ModifyCamera()
 // line 553, offset 0x0001fa20
	/* begin block 1 */
		// Start line: 555
		// Start offset: 0x0001FA20
		// Variables:
	// 		struct PAD *locPad; // $a3
	// 		struct _PLAYER *lp; // $a2

		/* begin block 1.1 */
			// Start line: 568
			// Start offset: 0x0001FAFC
			// Variables:
		// 		char *pNextCameraview; // $a0
		/* end block 1.1 */
		// End offset: 0x0001FB48
		// End Line: 578

		/* begin block 1.2 */
			// Start line: 585
			// Start offset: 0x0001FB64
			// Variables:
		// 		int cam_ang; // $a0
		// 		int length; // $a1
		/* end block 1.2 */
		// End offset: 0x0001FC04
		// End Line: 593
	/* end block 1 */
	// End offset: 0x0001FC10
	// End Line: 596

	/* begin block 2 */
		// Start line: 1106
	/* end block 2 */
	// End Line: 1107

	/* begin block 3 */
		// Start line: 1116
	/* end block 3 */
	// End Line: 1117

	/* begin block 4 */
		// Start line: 1117
	/* end block 4 */
	// End Line: 1118

	/* begin block 5 */
		// Start line: 1120
	/* end block 5 */
	// End Line: 1121

/* WARNING: Unknown calling convention yet parameter storage is locked */

void ModifyCamera(void)
{
	UNIMPLEMENTED();
	/*
	ushort *puVar1;
	char cVar2;
	int iVar3;
	char *pcVar4;
	uint uVar5;
	int iVar6;
	char *pcVar7;
	int iVar8;

	if ((((NoPlayerControl == 0) && (cameraview != 6)) && (events.cameraEvent == (_EVENT *)0x0)) &&
		(NumPlayers == 1)) {
		pcVar7 = &padbuffer + (uint)NumPlayers * 0x48;
		iVar8 = (uint)NumPlayers * 0x74 + 0xd96b4;
		while (iVar3 = iVar8, (char *)0xd92b7 < pcVar7) {
			puVar1 = (ushort *)(pcVar7 + 0xc);
			pcVar7 = pcVar7 + -0x48;
			iVar8 = iVar3 + -0x74;
			if ((*puVar1 & 0x100) != 0) {
				if (*(int *)(iVar3 + 0x3c) != FrameCnt + -1) {
					pcVar4 = &inGameCamera;
					cVar2 = inGameCamera;
					while (pcVar4 = pcVar4 + 1, cVar2 != *(char *)(iVar3 + 0x44)) {
						if (s__000aa109 + 1 < pcVar4) goto LAB_0001fb48;
						cVar2 = *pcVar4;
						pcVar4 = pcVar4;
					}
					*(char *)(iVar3 + 0x44) = pcVar4[1];
				}
			LAB_0001fb48:
				*(int *)(iVar3 + 0x3c) = FrameCnt;
				if (*(char *)(iVar3 + 0x44) == '\x01') {
					uVar5 = baseDir + 0x800U & 0xfff;
					if ((int)*(char *)(iVar3 + 0x49) < 1) {
						iVar6 = 0x168;
					}
					else {
						iVar6 = (int)((car_data[(int)*(char *)(iVar3 + 0x49)].ap.carCos)->colBox).vz;
					}
					*(int *)(iVar3 + 0x18) =
						basePos[0] + ((int)rcossin_tbl[uVar5 * 2] * (iVar6 + -0x3c) + 0x800 >> 0xc);
					*(int *)(iVar3 + 0x20) =
						basePos[2] + ((int)rcossin_tbl[uVar5 * 2 + 1] * (iVar6 + -0x3c) + 0x800 >> 0xc);
				}
			}
		}
	}
	return;*/
}



// decompiled code
// original method signature: 
// int /*$ra*/ CameraCollisionCheck()
 // line 609, offset 0x0001fc18
	/* begin block 1 */
		// Start line: 611
		// Start offset: 0x0001FC18
		// Variables:
	// 		struct MODEL *model; // $v1
	// 		struct COLLISION_PACKET *collide; // $t2
	// 		struct CELL_OBJECT *cop; // $t3
	// 		struct CELL_ITERATOR ci; // stack offset -168
	// 		struct VECTOR nearpoint; // stack offset -144
	// 		struct VECTOR surfacenormal; // stack offset -128
	// 		struct VECTOR surfacepoint; // stack offset -112
	// 		int cell_x; // $a0
	// 		int cell_z; // $a1
	// 		int xd; // $v1
	// 		int zd; // $a0
	// 		int num_cb; // $t5
	// 		int box_loop; // $t4
	// 		int sphere_sq; // $a2
	// 		int camera_size; // $s0
	// 		int count; // $s1
	// 		struct VECTOR temp_cam; // stack offset -96

		/* begin block 1.1 */
			// Start line: 659
			// Start offset: 0x0001FDF4
			// Variables:
		// 		struct MATRIX *mat; // $a2
		// 		struct VECTOR offset; // stack offset -80
		// 		struct VECTOR cam_vec; // stack offset -64
		// 		struct VECTOR normal; // stack offset -48
		// 		int xmin; // $a0
		// 		int xmax; // $a3
		// 		int ymin; // $t0
		// 		int ymax; // $v1
		// 		int zmin; // $a1
		// 		int zmax; // $a2
		// 		int tx; // $a3
		// 		int tz; // $a1
		/* end block 1.1 */
		// End offset: 0x0001FFD0
		// End Line: 694
	/* end block 1 */
	// End offset: 0x0002003C
	// End Line: 702

	/* begin block 2 */
		// Start line: 1273
	/* end block 2 */
	// End Line: 1274

	/* begin block 3 */
		// Start line: 1274
	/* end block 3 */
	// End Line: 1275

	/* begin block 4 */
		// Start line: 1291
	/* end block 4 */
	// End Line: 1292

/* WARNING: Unknown calling convention yet parameter storage is locked */

int CameraCollisionCheck(void)
{
	UNIMPLEMENTED();
	return 0;
	/*
	int iVar1;
	PACKED_CELL_OBJECT *ppco;
	CELL_OBJECT *pCVar2;
	uint uVar3;
	MODEL *pMVar4;
	int iVar5;
	int iVar6;
	int iVar7;
	int *piVar8;
	int iVar9;
	int *piVar10;
	int iVar11;
	CELL_ITERATOR aCStack168[3];
	int local_60;
	int local_58;
	int local_50;
	int local_4c;
	int local_48;

	iVar11 = 0;
	iVar1 = scr_z * 3 + -0x17e;
	do {
		local_60 = camera_position.vx + (iVar11 % 3) * 0x400 + -0x400;
		iVar7 = local_60 + units_across_halved;
		local_58 = camera_position.vz + (iVar11 / 3) * 0x400 + -0x400;
		if (iVar7 < 0) {
			iVar7 = iVar7 + 0x7ff;
		}
		iVar5 = local_58 + units_down_halved;
		if (iVar5 < 0) {
			iVar5 = iVar5 + 0x7ff;
		}
		if (0 < gCameraDistance) {
			ppco = GetFirstPackedCop(iVar7 >> 0xb, iVar5 >> 0xb, aCStack168, 0);
			pCVar2 = UnpackCellObject(ppco, &aCStack168[0].nearCell);
			while (pCVar2 != (CELL_OBJECT *)0x0) {
				pMVar4 = modelpointers1536[pCVar2->type];
				piVar8 = (int *)pMVar4->collision_block;
				if ((piVar8 != (int *)0x0) && ((pMVar4->flags2 & 0x800) == 0)) {
					iVar5 = (pCVar2->pos).vx;
					iVar7 = iVar5 - camera_position.vx;
					if (iVar7 < 0) {
						iVar7 = camera_position.vx - iVar5;
					}
					iVar6 = (pCVar2->pos).vz;
					iVar5 = iVar6 - camera_position.vz;
					if (iVar5 < 0) {
						iVar5 = camera_position.vz - iVar6;
					}
					piVar10 = piVar8 + 1;
					if (iVar7 * iVar7 + iVar5 * iVar5 <
						(int)pMVar4->bounding_sphere * (int)pMVar4->bounding_sphere + iVar1 * iVar1) {
						iVar7 = 0;
						if (0 < *piVar8) {
							do {
								uVar3 = (uint)pCVar2->yang;
								iVar9 = camera_position.vx - (pCVar2->pos).vx;
								iVar6 = camera_position.vz - (pCVar2->pos).vz;
								iVar5 = iVar9 * (&matrixtable)[uVar3].m[0] + iVar6 * (&matrixtable)[uVar3].m[6];
								if (iVar5 < 0) {
									iVar5 = iVar5 + 0xfff;
								}
								iVar6 = iVar9 * (&matrixtable)[uVar3].m[2] + iVar6 * (&matrixtable)[uVar3].m[8];
								if (iVar6 < 0) {
									iVar6 = iVar6 + 0xfff;
								}
								iVar9 = (iVar5 >> 0xc) - (int)*(short *)((int)piVar10 + 2);
								local_4c = (camera_position.vy - (pCVar2->pos).vy) - (int)*(short *)(piVar10 + 1);
								local_48 = (iVar6 >> 0xc) - (int)*(short *)((int)piVar10 + 6);
								iVar5 = (int)*(short *)((int)piVar10 + 10);
								local_50 = iVar9;
								if (iVar5 != 0) {
									local_50 = iVar9 * (&matrixtable)[iVar5].m[0] +
										local_48 * (&matrixtable)[iVar5].m[6];
									local_48 = iVar9 * (&matrixtable)[iVar5].m[2] +
										local_48 * (&matrixtable)[iVar5].m[8];
								}
								iVar5 = (uint)*(ushort *)((int)piVar10 + 0xe) << 0x10;
								if ((iVar5 >> 0x10 < 500) && ((short)*(ushort *)((int)piVar10 + 0x12) < 500)) break;
								iVar9 = (iVar5 >> 0x11) + iVar1;
								iVar6 = ((int)((uint)*(ushort *)((int)piVar10 + 0x12) << 0x10) >> 0x11) + iVar1;
								iVar5 = ((int)((uint)*(ushort *)(piVar10 + 4) << 0x10) >> 0x11) + iVar1;
								if (((-iVar9 < local_50) &&
									(((local_50 < iVar9 && (-iVar6 < local_48)) && (local_48 < iVar6)))) &&
									((-iVar5 < local_4c && (local_4c < iVar5)))) {
									return 1;
								}
								iVar7 = iVar7 + 1;
								piVar10 = piVar10 + 5;
							} while (iVar7 < *piVar8);
						}
					}
				}
				ppco = GetNextPackedCop(aCStack168);
				pCVar2 = UnpackCellObject(ppco, &aCStack168[0].nearCell);
			}
		}
		iVar11 = iVar11 + 1;
		if (8 < iVar11) {
			return 0;
		}
	} while (true);*/
}



// decompiled code
// original method signature: 
// void /*$ra*/ TurnHead(struct _PLAYER *lp /*$a0*/)
 // line 716, offset 0x00020a10
	/* begin block 1 */
		// Start line: 717
		// Start offset: 0x00020A10
	/* end block 1 */
	// End offset: 0x00020B08
	// End Line: 757

	/* begin block 2 */
		// Start line: 1432
	/* end block 2 */
	// End Line: 1433

	/* begin block 3 */
		// Start line: 2114
	/* end block 3 */
	// End Line: 2115

void TurnHead(_PLAYER *lp)
{
	UNIMPLEMENTED();
	/*
	byte bVar1;

	if ((paddCamera & 3) == 3) {
		if (pPlayerPed != (PEDESTRIAN *)0x0) {
			pPlayerPed->head_rot = 0;
		}
		goto LAB_00020ae8;
	}
	if ((paddCamera & 1) == 0) {
		if ((paddCamera & 2) == 0) {
			if (pPlayerPed != (PEDESTRIAN *)0x0) {
				pPlayerPed->head_rot = 0;
			}
			lp->headTimer = '\0';
			lp->headTarget = 0;
			goto LAB_00020ae8;
		}
		if (pPlayerPed != (PEDESTRIAN *)0x0) {
			pPlayerPed->head_rot = -0x200;
		}
		bVar1 = lp->headTimer;
		if (1 < bVar1) {
			lp->headTarget = -0x4000000;
			goto LAB_00020ae8;
		}
	}
	else {
		if (pPlayerPed != (PEDESTRIAN *)0x0) {
			pPlayerPed->head_rot = 0x200;
		}
		bVar1 = lp->headTimer;
		if (1 < bVar1) {
			lp->headTarget = 0x4000000;
			goto LAB_00020ae8;
		}
	}
	lp->headTimer = bVar1 + 1;
LAB_00020ae8:
	lp->headPos = lp->headPos + (lp->headTarget - lp->headPos >> 1);
	return;*/
}



// decompiled code
// original method signature: 
// void /*$ra*/ PlaceCameraFollowCar(struct _PLAYER *lp /*$s2*/)
 // line 777, offset 0x0002003c
	/* begin block 1 */
		// Start line: 778
		// Start offset: 0x0002003C
		// Variables:
	// 		int carheight; // $a0
	// 		int minimum_height; // $s1
	// 		int cammapht; // $s0
	// 		int new_angle; // $a0
	// 		int camPosVy; // $s1
	// 		struct VECTOR locCameraPos; // stack offset -48
	// 		int lbody; // $a0
	// 		int hbody; // $a3
	// 		int camExpandSpeed; // $s6

		/* begin block 1.1 */
			// Start line: 800
			// Start offset: 0x00020088
			// Variables:
		// 		struct _CAR_DATA *camCar; // $v1
		/* end block 1.1 */
		// End offset: 0x0002011C
		// End Line: 810
	/* end block 1 */
	// End offset: 0x0002050C
	// End Line: 893

	/* begin block 2 */
		// Start line: 1667
	/* end block 2 */
	// End Line: 1668

	/* begin block 3 */
		// Start line: 1743
	/* end block 3 */
	// End Line: 1744

void PlaceCameraFollowCar(_PLAYER *lp)
{
	UNIMPLEMENTED();
	/*
	_CAR_DATA *p_Var1;
	short sVar2;
	int iVar3;
	int iVar4;
	CAR_COSMETICS *pCVar5;
	uint uVar6;
	uint uVar7;
	int iVar8;
	int iVar9;
	int iVar10;

	iVar3 = (int)lp->cameraCarId;
	if (iVar3 < 0) {
		maxCameraDist = 0x352;
		iVar9 = -0xdc;
		iVar10 = 10;
	}
	else {
		pCVar5 = car_data[iVar3].ap.carCos;
		iVar10 = (int)(pCVar5->colBox).vy;
		iVar9 = iVar10 * -3 + 0x55;
		maxCameraDist = (int)(pCVar5->colBox).vz * 2 + iVar10 + 0xf8;
		iVar3 = car_data[iVar3].hd.wheel_speed + 0x800 >> 0xc;
		if (iVar3 < 0) {
			iVar3 = -iVar3;
		}
		iVar10 = 10;
		if ((9 < iVar3) && (gCameraDistance + 0x1e <= maxCameraDist)) {
			iVar10 = 0x14;
		}
	}
	if (pauseflag == 0) {
		TurnHead(lp);
	}
	camera_angle.vx = 0x19;
	uVar7 = lp->cameraAngle - (int)*(short *)((int)&lp->headPos + 2);
	if (pauseflag == 0) {
		if ((paddCamera & 3) == 3) {
			uVar7 = baseDir & 0xfff;
			goto LAB_000201cc;
		}
	}
	else {
		if (EditMode != 2) goto LAB_000201cc;
	}
	uVar6 = ((baseDir + gCameraAngle) - lp->cameraAngle) + 0x800U & 0xfff;
	iVar3 = uVar6 - 0x800;
	if (iVar3 < 0) {
		iVar3 = uVar6 - 0x7f9;
	}
	lp->cameraAngle = lp->cameraAngle + (iVar3 >> 3) & 0xfff;
LAB_000201cc:
	uVar7 = uVar7 & 0xfff;
	iVar8 = lp->cameraDist;
	iVar3 = rcossin_tbl[uVar7 * 2] * iVar8;
	if (iVar3 < 0) {
		iVar3 = iVar3 + 0xfff;
	}
	(lp->cameraPos).vx = basePos[0] + (iVar3 >> 0xc);
	iVar8 = rcossin_tbl[uVar7 * 2 + 1] * iVar8;
	if (iVar8 < 0) {
		iVar8 = iVar8 + 0xfff;
	}
	(lp->cameraPos).vz = basePos[2] + (iVar8 >> 0xc);
	(lp->cameraPos).vy = basePos[1];
	iVar3 = MapHeight(&lp->cameraPos);
	iVar8 = (iVar9 - iVar3) + -100;
	(lp->cameraPos).vy = iVar9 - basePos[1];
	iVar9 = MapHeight((VECTOR *)basePos);
	if (iVar8 < (lp->cameraPos).vy) {
		iVar4 = iVar9 - iVar3;
		if (iVar4 < 0) {
			iVar4 = iVar3 - iVar9;
		}
		if (iVar4 < 900) {
			camera_angle.vx = (short)((lp->cameraPos).vy - iVar8 >> 1) + 0x19;
			(lp->cameraPos).vy = iVar8;
		}
	}
	jcam = car_data + 0x14;
	ClearMem((char *)(car_data + 0x14), 0x29c);
	jcam->controlType = '\x05';
	p_Var1 = jcam;
	iVar3 = maxCameraDist;
	if ((int)lp->cameraCarId < 0) {
		pCVar5 = (CAR_COSMETICS *)0x0;
	}
	else {
		pCVar5 = car_data[(int)lp->cameraCarId].ap.carCos;
	}
	(jcam->ap).carCos = pCVar5;
	(p_Var1->hd).direction = uVar7;
	gCameraDistance = iVar3;
	iVar9 = iVar3 * rcossin_tbl[uVar7 * 2] + 0x800;
	iVar9 = basePos[0] + ((iVar9 >> 0xc) - (iVar9 >> 0x1f) >> 1);
	(p_Var1->hd).where.t[0] = iVar9;
	(p_Var1->hd).oBox.location.vx = iVar9;
	iVar9 = -(lp->cameraPos).vy;
	(p_Var1->hd).where.t[1] = iVar9;
	(p_Var1->hd).oBox.location.vy = iVar9;
	iVar3 = iVar3 * rcossin_tbl[uVar7 * 2 + 1] + 0x800;
	iVar3 = basePos[2] + ((iVar3 >> 0xc) - (iVar3 >> 0x1f) >> 1);
	(p_Var1->hd).where.t[2] = iVar3;
	(p_Var1->hd).oBox.location.vz = iVar3;
	CheckScenaryCollisions(car_data + 0x14);
	p_Var1 = jcam;
	iVar10 = lp->cameraDist + iVar10;
	iVar3 = gCameraDistance;
	if (iVar10 < gCameraDistance) {
		iVar3 = iVar10;
	}
	lp->cameraDist = iVar3;
	iVar3 = -(p_Var1->hd).where.t[1];
	(p_Var1->hd).where.t[1] = iVar3;
	(lp->cameraPos).vy = iVar3;
	uVar7 = (p_Var1->hd).direction & 0xfff;
	(p_Var1->hd).direction = uVar7;
	iVar3 = lp->cameraDist;
	iVar10 = basePos[0] + (iVar3 * rcossin_tbl[uVar7 * 2] + 0x800 >> 0xc);
	(lp->cameraPos).vx = iVar10;
	iVar3 = basePos[2] +
		(iVar3 * rcossin_tbl[((p_Var1->hd).direction & 0xfffU) * 2 + 1] + 0x800 >> 0xc);
	(lp->cameraPos).vz = iVar3;
	sVar2 = ratan2(basePos[0] - iVar10, basePos[2] - iVar3);
	camera_angle.vy = -sVar2 & 0xfff;
	camera_angle.vz = 0;
	SetGeomScreen(0x100);
	scr_z = 0x100;
	switch_detail_distance = (int)&DAT_00002710;
	BuildWorldMatrix();
	return;*/
}



// decompiled code
// original method signature: 
// void /*$ra*/ PlaceCameraAtLocation(struct _PLAYER *lp /*$s1*/, int zoom /*$s2*/)
 // line 904, offset 0x00020904
	/* begin block 1 */
		// Start line: 905
		// Start offset: 0x00020904
		// Variables:
	// 		int d; // $s0

		/* begin block 1.1 */
			// Start line: 911
			// Start offset: 0x00020930
			// Variables:
		// 		struct VECTOR temp; // stack offset -32
		/* end block 1.1 */
		// End offset: 0x00020930
		// End Line: 913
	/* end block 1 */
	// End offset: 0x000209F8
	// End Line: 950

	/* begin block 2 */
		// Start line: 2237
	/* end block 2 */
	// End Line: 2238

	/* begin block 3 */
		// Start line: 1808
	/* end block 3 */
	// End Line: 1809

	/* begin block 4 */
		// Start line: 2240
	/* end block 4 */
	// End Line: 2241

void PlaceCameraAtLocation(_PLAYER *lp, int zoom)
{
	UNIMPLEMENTED();
	/*
	int iVar1;
	int iVar2;
	VECTOR local_20;

	iVar2 = 0;
	if (tracking_car != '\0') {
		local_20.vx = basePos[0];
		local_20.vy = -basePos[1];
		local_20.vz = basePos[2];
		iVar2 = PointAtTarget(&lp->cameraPos, &local_20, &camera_angle);
		if (16000 < iVar2) {
			lp->cameraView = '\0';
			return;
		}
		if (zoom == 0) {
			iVar1 = 0x100;
		}
		else {
			scr_z = (iVar2 >> 4) + 0x100;
			iVar1 = 800;
			if (scr_z < 0x321) goto LAB_000209b0;
		}
		scr_z = iVar1;
	}
LAB_000209b0:
	if (scr_z < 0x100) {
		scr_z = 0x100;
	}
	SetGeomScreen(scr_z);
	switch_detail_distance = (int)(&DAT_00002710 + iVar2 * 4);
	BuildWorldMatrix();
	return;
	*/
}



// decompiled code
// original method signature: 
// int /*$ra*/ PointAtTarget(struct VECTOR *pPosition /*$a0*/, struct VECTOR *pTarget /*$a1*/, struct SVECTOR *pAngleVec /*$s0*/)
 // line 960, offset 0x00020b08
	/* begin block 1 */
		// Start line: 961
		// Start offset: 0x00020B08
		// Variables:
	// 		struct VECTOR delta; // stack offset -32
	// 		int d; // $s1
	/* end block 1 */
	// End offset: 0x00020BC0
	// End Line: 976

	/* begin block 2 */
		// Start line: 2394
	/* end block 2 */
	// End Line: 2395

	/* begin block 3 */
		// Start line: 2598
	/* end block 3 */
	// End Line: 2599

	/* begin block 4 */
		// Start line: 2602
	/* end block 4 */
	// End Line: 2603

int PointAtTarget(VECTOR *pPosition, VECTOR *pTarget, SVECTOR *pAngleVec)
{
	UNIMPLEMENTED();
	return 0;
	/*
	short sVar1;
	int iVar2;
	int iVar3;
	int iVar4;
	int iVar5;
	int iVar6;

	iVar6 = pTarget->vx - pPosition->vx;
	iVar4 = pTarget->vz - pPosition->vz;
	iVar2 = pTarget->vy;
	iVar5 = pPosition->vy;
	iVar3 = SquareRoot0(iVar6 * iVar6 + iVar4 * iVar4);
	sVar1 = ratan2(iVar3, iVar2 - iVar5);
	pAngleVec->vx = 0x400U - sVar1 & 0xfff;
	sVar1 = ratan2(iVar6, iVar4);
	pAngleVec->vy = -sVar1 & 0xfff;
	pAngleVec->vz = 0;
	return iVar3;
	*/
}



// decompiled code
// original method signature: 
// void /*$ra*/ PlaceCameraInCar(struct _PLAYER *lp /*$s3*/, int BumperCam /*$a1*/)
 // line 987, offset 0x0002050c
	/* begin block 1 */
		// Start line: 988
		// Start offset: 0x0002050C
		// Variables:
	// 		struct _CAR_DATA *cp; // $s2

		/* begin block 1.1 */
			// Start line: 1044
			// Start offset: 0x000207BC
		/* end block 1.1 */
		// End offset: 0x000207CC
		// End Line: 1045

		/* begin block 1.2 */
			// Start line: 1049
			// Start offset: 0x000207E0
		/* end block 1.2 */
		// End offset: 0x00020800
		// End Line: 1052
	/* end block 1 */
	// End offset: 0x00020904
	// End Line: 1077

	/* begin block 2 */
		// Start line: 2104
	/* end block 2 */
	// End Line: 2105

	/* begin block 3 */
		// Start line: 2199
	/* end block 3 */
	// End Line: 2200

void PlaceCameraInCar(_PLAYER *lp, int BumperCam)
{
	UNIMPLEMENTED();
	/*
	ushort uVar1;
	uint uVar2;
	_CAR_DATA *p_Var3;
	int iVar4;

	p_Var3 = (_CAR_DATA *)0x0;
	if (-1 < (int)lp->cameraCarId) {
		p_Var3 = car_data + (int)lp->cameraCarId;
	}
	viewer_position.vx = 0;
	if (p_Var3 == (_CAR_DATA *)0x0) {
		viewer_position.vz = 0;
		viewer_position.vy = viewer_position.vy + 0x2a + (int)lp->pPed->head_pos;
	}
	else {
		viewer_position.vy = 7;
		viewer_position.vz = (int)(((p_Var3->ap).carCos)->colBox).vz + -0x50;
	}
	if ((paddCamera & 3) == 3) {
		viewer_position.vz = 0;
	}
	if (p_Var3 == (_CAR_DATA *)0x0) {
		uVar2 = baseDir & 0xfff;
		(lp->cameraPos).vx = basePos[0];
		(lp->cameraPos).vy = -basePos[1];
		(lp->cameraPos).vz = basePos[2];
		(lp->cameraPos).vx = basePos[0] + (rcossin_tbl[uVar2 * 2] * viewer_position.vz + 0x800 >> 0xc);
		(lp->cameraPos).vy = viewer_position.vy - basePos[1];
		iVar4 = rcossin_tbl[uVar2 * 2 + 1] * viewer_position.vz;
	}
	else {
		uVar2 = baseDir & 0xfff;
		(lp->cameraPos).vx = basePos[0] + (rcossin_tbl[uVar2 * 2] * viewer_position.vz + 0x800 >> 0xc);
		(lp->cameraPos).vy = viewer_position.vy - basePos[1];
		iVar4 = rcossin_tbl[uVar2 * 2 + 1] * viewer_position.vz;
	}
	(lp->cameraPos).vz = basePos[2] + (iVar4 + 0x800 >> 0xc);
	TurnHead(lp);
	if ((paddCamera & 3) == 3) {
		uVar1 = 0x800 - (short)baseDir;
	}
	else {
		uVar1 = *(short *)((int)&lp->headPos + 2) - (short)baseDir;
	}
	camera_angle.vy = uVar1 & 0xfff;
	SetGeomScreen(0x100);
	scr_z = 0x100;
	if (p_Var3 == (_CAR_DATA *)0x0) {
		ClearMem((char *)&inv_camera_matrix, 0x20);
		uVar2 = 0x800U - baseDir & 0xfff;
		inv_camera_matrix.m[0][0] = rcossin_tbl[uVar2 * 2 + 1];
		inv_camera_matrix.m[0][2] = rcossin_tbl[uVar2 * 2];
		inv_camera_matrix.m[1][1] = 0x1000;
		inv_camera_matrix.m[2][0] = -inv_camera_matrix.m[0][2];
		inv_camera_matrix.m[2][2] = inv_camera_matrix.m[0][0];
	}
	else {
		InvertMatrix(&(p_Var3->hd).drawCarMat, &inv_camera_matrix);
	}
	if ((paddCamera & 3) == 3) {
		if (p_Var3 != (_CAR_DATA *)0x0) {
			viewer_position.vz = 0xaa;
		}
	}
	else {
		_RotMatrixY(&inv_camera_matrix, 0x800);
		_RotMatrixY(&inv_camera_matrix, *(short *)((int)&lp->headPos + 2));
		if (p_Var3 != (_CAR_DATA *)0x0) {
			viewer_position.vz = -0xaa;
		}
	}
	MulMatrix0(&aspect, &inv_camera_matrix, &inv_camera_matrix);
	InvertMatrix(&inv_camera_matrix, &camera_matrix);
	face_camera_work.m[0][0] = 0x1000;
	face_camera_work.m[0][2] = 0;
	face_camera_work.m[2][0] = 0;
	face_camera_work.m[2][2] = 0x1000;
	RotMatrixY(-(int)camera_angle.vy & 0xfff, &face_camera_work);
	MulMatrix0(&inv_camera_matrix, &face_camera_work, &face_camera);
	viewer_position.vy = -0x28;
	SetRotMatrix(&camera_matrix);
	_MatrixRotate(&viewer_position);
	(lp->cameraPos).vx = (lp->cameraPos).vx + viewer_position.vx;
	(lp->cameraPos).vy = (lp->cameraPos).vy + viewer_position.vy;
	(lp->cameraPos).vz = (lp->cameraPos).vz + viewer_position.vz;
	switch_detail_distance = (int)&DAT_00002710;
	return;*/
}



// decompiled code
// original method signature: 
// int /*$ra*/ OK_To_Zoom()
 // line 1083, offset 0x00020bc0
	/* begin block 1 */
		// Start line: 1085
		// Start offset: 0x00020BC0
		// Variables:
	// 		int old_z; // $s0
	// 		struct VECTOR temp; // stack offset -24
	/* end block 1 */
	// End offset: 0x00020C70
	// End Line: 1114

	/* begin block 2 */
		// Start line: 2753
	/* end block 2 */
	// End Line: 2754

	/* begin block 3 */
		// Start line: 2861
	/* end block 3 */
	// End Line: 2862

	/* begin block 4 */
		// Start line: 2862
	/* end block 4 */
	// End Line: 2863

	/* begin block 5 */
		// Start line: 2872
	/* end block 5 */
	// End Line: 2873

/* WARNING: Unknown calling convention yet parameter storage is locked */

int OK_To_Zoom(void)
{
	UNIMPLEMENTED();
	return 0;
	/*
	int iVar1;
	int iVar2;
	VECTOR local_18;

	iVar1 = scr_z;
	local_18.vx = player.pos[0];
	local_18.vy = -player.pos[1];
	local_18.vz = player.pos[2];
	iVar2 = dist(&camera_position, &local_18);
	scr_z = (iVar2 >> 4) + 0x100;
	if (800 < scr_z) {
		scr_z = 800;
	}
	if (scr_z < 0x100) {
		scr_z = 0x100;
	}
	iVar2 = CameraCollisionCheck();
	scr_z = iVar1;
	return (uint)(iVar2 == 0);*/
}



// decompiled code
// original method signature: 
// void /*$ra*/ SetBasePos(struct VECTOR *pVec /*$a0*/)
 // line 1119, offset 0x00020c70
	/* begin block 1 */
		// Start line: 2945
	/* end block 1 */
	// End Line: 2946

	/* begin block 2 */
		// Start line: 2951
	/* end block 2 */
	// End Line: 2952

	/* begin block 3 */
		// Start line: 2952
	/* end block 3 */
	// End Line: 2953

void SetBasePos(VECTOR *pVec)
{
	UNIMPLEMENTED();
	/*
	basePos[0] = pVec->vx;
	basePos[1] = pVec->vy;
	basePos[2] = pVec->vz;
	return;
	*/
}




